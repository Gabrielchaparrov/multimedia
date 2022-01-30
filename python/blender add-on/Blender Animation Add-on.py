import bpy
from bpy import data as D
from bpy import context as C
from mathutils import *
from math import *
import random


bl_info = \
    {
        "name" : "Interpolaciones y control de velocidades",
        "author" : "Gabriel Chaparro Villaescusa, Iris Dauder González y Silvia Del Toro Tornero",
        "blender" : (2, 80, 0),
        "category" : "Object",
    }
            
########   interpola_valores   ##############
########   
########    
########
########   f1, f2              Fotograma clave anterior y posterior al fotograma a interpolar.
########   x1, x2              Posición de los fotogramas anterior y posterior al fotograma a interpolar.
########   f                   Fotograma a interpolar.
########   nom_metodo          Metodo a utilizar para la interpolación.
########   x0, x3              Posición anterior a x1 y posición posterior a x2. (Requerido para Catmull-Rom)
########   ten                 Tensión. (Requerido para Catmull-Rom)
########   v1, v2              Velocidad del fotograma anterior y posterior al fotograma a interpolar. (Requerido para Hermite)
########                       ########
def interpola_valores(f1, f2, x1, x2, f, nom_metodo, x0, x3, ten, v1, v2):
    u = ((f-f1)/(f2-f1)) #Tiempo normalizado en el segmento donde se realiza la interpolación
    
    if (nom_metodo == 'lin'):   #Interpolación lineal
        pos = lineal(x1, x2, u)
    
    elif (nom_metodo == 'her'): #Interpolación por el método de Hermite
        pos = hermite(u, x1, x2, v1, v2)
    
    elif(nom_metodo == 'cat'):  #Interpolación por el método de Catmull-Rom
        pos = catrom(u, x0, x1, x2, x3, ten)
        
    else:
        print('Error')
        pos = 0
        
    return pos

########   lineal    ##############
########   
########   x1, x2    Posición de los fotogramas anterior y posterior al fotograma a interpolar.
########   u         Tiempo normalizado transcurrido en el intervalo donde se interpola
########             ########
def lineal (x1, x2, u):
    
    ec1 = x2-x1
    ec2 = u*ec1
    ec3 = x1 + ec2
    
    pos = ec3
    
    return pos

########   hermite    ##############
########  
########   u         Tiempo normalizado transcurrido en el intervalo donde se interpola 
########   x1, x2    Posición de los fotogramas anterior y posterior al fotograma a interpolar.
########   v1, v2    Velocidad de los fotogramas anterior y posterior al fotograma a interpolar.
########             ########
def hermite (u, x1, x2, v1, v2):
    #Coeficientes de Hermite
    a = 1-(3*(u*u))+(2*(u*u*u))
    b = u*u * (3-(2*u))
    c = u*((u-1)*(u-1))
    d = u*u*(u-1)
    
    #Polinomio de Hermite
    pos = (a*x1) + (b*x2) + (c*v1) + (d*v2)
    
    return pos


########   catrom    ##############
########  
########   u         Tiempo normalizado transcurrido en el intervalo donde se interpola 
########   x0, x3    Posición anterior a x1 y posición posterior a x2.
########   x1, x2    Posición de los fotogramas anterior y posterior al fotograma a interpolar.
########   ten       Tensión.
########             ########
def catrom(u, x0, x1, x2, x3, ten):
    v1 = (x2-x0) * ten
    v2 = (x3-x1) * ten  #Calculamos las velocidades como diferencia de de las posiciones anterior y posterior.
    return hermite(u, x1, x2, v1, v2)   #Interpolamos con Hermite


########   get_ampl    ##############
########  
########   amp_max         Amplitud máxima que puede alcanzar la trayectoria
########
########   Función que genera desplazamientos aleatorios en cualquier dirección
def get_ampl(amp_max): 

    x = random.uniform(0, amp_max)
    y = random.uniform(0, amp_max)
    z = random.uniform(0, amp_max)
    
    modulo = sqrt((x * x) + (y * y) + (z * z)) #Módulo del vector
    
    while(modulo > amp_max): #El módulo debe ser menor o igual a la amplitud máxima
        x = x - 0.001
        y = y - 0.001
        z = z - 0.001
        modulo = sqrt((x * x) + (y * y) + (z * z))

    return Vector((x, y, z)) #Vector aleatorio


########   get_pos    ##############
########  
########   fotogramas_clave     Lista de fotogramas clave introducidos por el usuario
########   coordenadas          Lista de coordenadas obtenidas de cada fotograma clave
########   accion               Acción del objeto seleccionado
########   frame                Número de frame que se va a interpolar
########   interpolacion        Método de interpolación a realizar
########   vel                  Lista de velocidades obtenidas de cada fotograma clave
########   Función que obtiene la información necesaria para interpolar el fotograma actual y devuelve el punto interpolado asociado a ese fotograma.
def get_pos(fotogramas_clave, coordenadas, accion, frame, interpolacion, vel):
    ten = bpy.context.object.Tension #Obtener la tensión establecida por el usuario en el panel
        
    coordenadasx = coordenadas[0]
    coordenadasy = coordenadas[1]
    coordenadasz = coordenadas[2]
    
    #Vector de velocidades
    velx=[]
    vely=[]
    velz=[]
    
    for v in vel:
        velx.append(v[1][0])
        vely.append(v[1][1])
        velz.append(v[1][2])
    
    iterador = 0
    encontrado = False
        
    while(encontrado != True and iterador < (len(fotogramas_clave)-1)): #Bucle que encuentra el fotograma actual que se va a interpolar
            
        if(fotogramas_clave[iterador] <= frame and fotogramas_clave[iterador+1] > frame):
            encontrado = True
            
            f1 = fotogramas_clave[iterador]
            f2 = fotogramas_clave[iterador+1]
            
            x1 = coordenadasx[iterador]
            vx1 = velx[iterador]
            x2 = coordenadasx[iterador+1]
            vx2 = velx[iterador+1]
            
            y1 = coordenadasy[iterador]
            vy1 = vely[iterador]
            y2 = coordenadasy[iterador+1] 
            vy2 = vely[iterador+1]
            
            z1 = coordenadasz[iterador]
            vz1 = velz[iterador]
            z2 = coordenadasz[iterador+1]	
            vz2 = velz[iterador+1]
            
            #Índices para el método de Catmull-Rom
            if(iterador > 0 and iterador <= (len(fotogramas_clave)-2)):
                arg_0 = iterador-1
                arg_3 = iterador+1
            
            elif(iterador == 0):
                arg_0 = 0
                arg_3 = iterador+1
                
            else:
                arg_0 = iterador-1
                arg_3 = iterador
                
            x0 = coordenadasx[arg_0]
            y0 = coordenadasy[arg_0]
            z0 = coordenadasz[arg_0]
            x3 = coordenadasx[arg_3]
            y3 = coordenadasy[arg_3]
            z3 = coordenadasz[arg_3]
        
        else:
            iterador = iterador + 1	
        
            
            
    if(encontrado == True): #Interpolación de las tres coordenadas
        valorx = interpola_valores(f1, f2, x1, x2, frame, interpolacion, x0, x3, ten, vx1, vx2)
        valory = interpola_valores(f1, f2, y1, y2, frame, interpolacion, x0, x3, ten, vy1, vy2)
        valorz = interpola_valores(f1, f2, z1, z2, frame, interpolacion, x0, x3, ten, vz1, vz2)
        
        
    elif(frame <= fotogramas_clave[0]): #Primer intervalo
        valorx = coordenadasx[0] 
        valory = coordenadasy[0] 
        valorz = coordenadasz[0]
        
        
    elif(frame >= fotogramas_clave[len(fotogramas_clave)-1]):   #Último intervalo
        valorx = coordenadasx[len(fotogramas_clave)-1] 
        valory = coordenadasy[len(fotogramas_clave)-1] 
        valorz = coordenadasz[len(fotogramas_clave)-1]
        
        
    return(Vector((valorx, valory, valorz)))    #Vector con las tres coordenadas interpoladas


########   createEmptiesAndGetVelocityVector(action)    ##############
########  
########   action         Acción del objeto seleccionado
########
######## function to create or update empties
######## returns a vector of tuples (frame,velocity determined by the orientation and scale) of each empty
def createEmptiesAndGetVelocityVector(action):
    actionName = action.name
    
    # check if exists a collection with the same name of the action
    collection = bpy.data.collections.get(actionName)
    #print(collection)
    if collection is None:
        # if the collection not exists then create it
        collection = bpy.data.collections.new(actionName)
        bpy.context.scene.collection.children.link(collection)
        
    cx = action.fcurves.find('location',index=0).keyframe_points
    cy = action.fcurves.find('location',index=1).keyframe_points
    cz = action.fcurves.find('location',index=2).keyframe_points
 
    # for each keyframe check if exists an empty object in the collection
    for i in range(len(cx)):
        
        # get the position of the KF
        pos = Vector([cx[i].co[1], cy[i].co[1], cz[i].co[1]])
        
        emptyObj = collection.objects.get(str(i))
        if emptyObj is None:
            # if not exists create it
            emptyObj = bpy.data.objects.new( "empty", None )
            emptyObj.empty_display_size = 0.2
            emptyObj.empty_display_type = 'SINGLE_ARROW'
            emptyObj.name = str(i)
            collection.objects.link(emptyObj)
            
            # else set the initial orientation to look at the next KFb
            if i+1 < len(cx):
                pos2 = Vector([cx[i+1].co[1], cy[i+1].co[1], cz[i+1].co[1]])
                rot = (pos2 - pos).to_track_quat('Z','Y')
                emptyObj.rotation_euler = rot.to_euler()
            
            
        # set the location to the empty object
        emptyObj.location = Vector([cx[i].co[1], cy[i].co[1], cz[i].co[1]])
        
    # force update the scene, necessary if new empties have been created
    bpy.context.view_layer.update()
        
    # for each keyframe get the velocity (scaled direction of the single arrow)
    # create a vector of tuples (frame, velocity) where velocity is a Vector
    velocityVector = []
    for i in range(len(cx)):
        velocity = collection.objects[str(i)].matrix_world.col[2][:3]
        velocityVector.append((cx[i].co[0], velocity))
    return velocityVector


########   updateCustomVelocityProperty(action, customPropertyName, velocityVector)    ##############
########  
########   action                   Acción del objeto seleccionado
########   customPropertyName       Nombre de la propiedad personalizada
########   velocityVector           Vector de velocidades que actualiza las curvas de velocidad
########   function to create or update empties
########   returns a vector of tuples (frame,velocity determined by the orientation and scale) of each empty
########   function to update the values of the fcurve asignated to a custom property
def updateCustomVelocityProperty(action, customPropertyName, velocityVector):
    bpy.types.Object.velocity = bpy.props.FloatVectorProperty(name=customPropertyName)
    
    for i in range(3):
        
        # Remove the previous fcurve
        v = action.fcurves.find(customPropertyName, index=i)
        if v is not None:
            action.fcurves.remove(v)
        # create a clean new fcurve
        action.fcurves.new(customPropertyName, index=i)
        v = action.fcurves.find(customPropertyName, index=i)
            
        # add all the KFs to the fcurve
        for kf in velocityVector:         	
            v.keyframe_points.insert(kf[0], kf[1][i])


########   main(context)     ##############
########
########   context           Contexto del objeto
########
########   Función principal  ########
def main(context):
    
    objeto = bpy.context.selected_objects[0]                             #Objeto seleccionado
    accion = bpy.context.selected_objects[0].animation_data.action       #Acción del objeto seleccionado
    
    #Mantener la accion original
    objeto.animation_data_clear()                       
    objeto.animation_data_create()
    objeto.animation_data.action = accion.copy()

    
    #Se recogen las coordenadas de los fotogramas clave introducidos por el usuario
    cx = bpy.context.selected_objects[0].animation_data.action.fcurves.find('location',index=0)
    cy = bpy.context.selected_objects[0].animation_data.action.fcurves.find('location',index=1)
    cz = bpy.context.selected_objects[0].animation_data.action.fcurves.find('location',index=2)
    

    #Obtención de parametros introducidos por el usuario
    
    interpolacion = objeto.Metodo                          #Recoge el método de interpolación elegido por el usuario en el panel
    oscilacion_aleatoria = objeto.Oscilacion               #Recoge si el usuario ha escogido oscilación en el panel
    tipo_vel = objeto.tipo_vel                             #Recoge el tipo de velocidad escogido por el usuario
    aplitud = objeto.Amplitud                              #Recoge la amplitud introducida por el usuario en el panel
    nframes = int(cx.keyframe_points[-1].co[0])            #Recoge el número de fotogramas clave introducidos por el usuario
    inicio = int(cx.keyframe_points[0].co[0])              #Recoge el primer fotograma clave introducido por el usuario
    salto = objeto.Intervalos                              #Recoge la frecuencia con la que el usuario desea que se inserten fotogramas en la interpolación
    nombre_propiedad = objeto.nombreProp                   #Recoge el nombre de la propiedad personalizada para longitud en velocidad modificada
    velocidadCte = bpy.context.object.velocidadCte         #Recoge la velocidad constante con la que el usuario desea que se recorra la trayectoria
    cuaterniones = objeto.Cuaterniones                     #Recoge si el usuario desea orientar con cuaterniones
    eje = objeto.Eje                                       #Recoge el eje de orientación del objeto
    ejeL = objeto.EjeLateral                               #Recoge el eje lateral respecto a la orientacion del objeto
    nombre_propiedad_angulo = objeto.nombrePropAng         #Recoge el nombre de la propiedad personalizada para el angulo de alabeo
    
    #Inicialmente, no hay nuevas propiedades
    nueva_propiedad_angulo = False;                     
    nueva_propiedad = False

    
    #Se genera el vector de velocidades y se actualizan las flechas con esas velocidades
    vel = createEmptiesAndGetVelocityVector(accion)
    updateCustomVelocityProperty(accion, 'velocity', vel)
    
    coordenadasx = []
    coordenadasy = []
    coordenadasz = []
    fotogramas_clave = []
            
    for (x, y, z) in zip(cx.keyframe_points, cy.keyframe_points, cz.keyframe_points):   #Se realizan listas con los todos los fotogramas clave y sus posiciones por separado
        fotogramas_clave = fotogramas_clave + [x.co[0]]
        coordenadasx = coordenadasx + [x.co[1]]
        coordenadasy = coordenadasy + [y.co[1]]
        coordenadasz = coordenadasz + [z.co[1]]
        
    coordenadas = [coordenadasx, coordenadasy, coordenadasz]
    
    ini = int(fotogramas_clave[0])
    fin = int(fotogramas_clave[len(fotogramas_clave)-1])
    
    if(tipo_vel != 'pred'):                        #Si la velocidad no es la resultante de la interpolacion
        pack = crear_tabla(ini, fin, fotogramas_clave, coordenadas, accion, interpolacion, vel)  #Creamos la tabla de tiempo - posicion
        longitud_total = pack[1][len(pack[1])-1]   #La longitud total sera la ultima de esta tabla
        
        fin = bpy.data.scenes["Scene"].frame_end   #Nuevo fotograma final
        inicio = pack[0][0]                        #Fotograma inicial
    
    for i in range(inicio, fin+1, salto):
        if(tipo_vel != 'pred'):                 #Si la velocidad no es la resultante de la interpolacion
            t = (i-inicio)/(24 / velocidadCte)  #La velocidad esta en m/seg
        
            if(tipo_vel == 'const'):            #Si la velocidad es constante
                l_deseada = t
            else:                               #Si la velocidad es modificada por el usuario
                context.scene.frame_set(i)      #Nos ubicamos en el frame actual
                if(nombre_propiedad in bpy.context.object):
                    l_deseada = bpy.context.object[nombre_propiedad]    #Si existe la propiedad personalizada, obtenemos la longitud de ella
                else:
                    l_deseada = t                                       #Si no existe, creamos una nueva avisando al usuario de ello.
                    nueva_propiedad = True

            frame_antiguo = buscar_tabla(l_deseada, pack)      #Buscamos en la tabla el frame donde se alcanza la longitud deseada
            
        else:
            frame_antiguo = i                                   #Si la velocidad es la resultante de la interpolacion, no hay cambios
            
        if(nombre_propiedad_angulo not in bpy.context.object):
            nueva_propiedad_angulo = True;
        
        #Calculamos la posicion despues de la reparametrizacion
        posicion = get_pos(fotogramas_clave, coordenadas, accion.name, frame_antiguo, interpolacion, vel)
        
        if (oscilacion_aleatoria):      #Si el usuario desea oscilacion aleatoria
            vec = get_ampl(aplitud)     #Obtenemos la oscilacion y la aplicamos en cada coordenada
            posicion[0]+= vec[0]
            posicion[1]+=vec[1]
            posicion[2]+=vec[2]
            
        #Insertamos fotogramas resultantes de la interpolacion    
        objeto.location = posicion
        objeto.keyframe_insert(data_path='location', frame=i)
        
        
        if(cuaterniones):   #Si el usuario desea orientacion mediante cuaterniones
        
            #Calculo del vector tangente normalizado a la posicion actual
            t = (get_pos(fotogramas_clave, coordenadas, accion.name, frame_antiguo+1, interpolacion, vel) - get_pos(fotogramas_clave, coordenadas, accion.name, frame_antiguo-1, interpolacion, vel))/2
            t = t.normalized()  
            
            #Eje de orientacion del objeto introducido por el usuario
            if(eje == "X"):
                e = Vector((1,0,0))
            elif(eje == "Y"):
                e = Vector((0,1,0))
            else:
                e = Vector((0,0,1))

            #Obtencion del cuaternion que orienta al objeto en la direccion correspondiente
            q = get_quat_from_vecs(e, t)
            
            #Eje lateral respecto a la orientacion del objeto introducido por el usuario
            if(ejeL == "X"):
                el = Vector((1,0,0))
            elif(ejeL == "Y"):
                el = Vector((0,1,0))
            else:
                el = Vector((0,0,1))
                
            #Si no esta la nueva propiedad
            if(nueva_propiedad_angulo == False and bpy.context.object.angAlabeo == True):
                context.scene.frame_set(i)
                angulo = bpy.context.object[nombre_propiedad_angulo]  #Establecemos la nueva propiedad con el angulo y el nombre deseado
            else:
                angulo = 0                                            #Angulo por defecto
                
            l = get_lat_vec(t)  #Obtenemos la direccion en la que queremos orientar el eje lateral
            
            #Orientamos el eje lateral en la direccion deseada, calculamos el angulo de alabeo y obtenemos el cuaternion de rotacion extra
            qextra = get_quat_rot(el, t, q, l, angulo)
        
            objeto.rotation_quaternion = qextra @ q                             #Orientacion final
            objeto.keyframe_insert(data_path='rotation_quaternion', frame=i)    #Aplicamos la orientacion
        
    #Avisos e informacion adicional para el usuario 
    if(nueva_propiedad == True):
        bpy.ops.wm.properties_add(data_path="object")
        bpy.context.window_manager.popup_menu(draw, title="¡Atención!", icon='INFO')
        
    if(nueva_propiedad_angulo == True and bpy.context.object.angAlabeo == True):
        bpy.ops.wm.properties_add(data_path="object")
        bpy.context.window_manager.popup_menu(draw2, title="¡Atención!", icon='INFO')
     
########   get_quat_from_vecs(e, t) ##############
########
########   e    Eje original del objeto
########   t    Vector tangente a la curva
########
########    Función que calcula y devuelve el cuaternion que alinea e con t  ########
def get_quat_from_vecs(e, t):
    
    eje_z = e
    eje_z_objeto = t
    
    eje_rot = eje_z.cross(eje_z_objeto)
    eje_rot = eje_rot.normalized()
    
    cos_ang = eje_z.dot(eje_z_objeto)
    ang = acos(cos_ang)
    
    sang2 = sin(ang/2)
    q = Quaternion((cos(ang/2), eje_rot[0]*sang2, eje_rot[1]*sang2, eje_rot[2]*sang2))
    
    return q 

########   get_lat_vec(t) ##############
########
########   t    Vector tangente a la curva
########
########    Función que alinea la tangente con un vector completamente horizontal y perpendicular a el
def get_lat_vec(t):

    z = Vector((0,1,0)) #Componente horizontal y perpendicular a t
    l = z.cross(t)
    l = l.normalized()
    
    return l 

########   get_quat_rot(el, t, q, l, angulo) ##############
########
########   el       Vector para controlar la orientacion lateral
########    t       Angulo de rotacion
########    q       Cuaternion que alinea el eje principal
########    l       Vector que forma el angulo con 'el'
########    angulo  Angulo para la rotacion adicional
########    
######## Función que devuelve un cuaternión donde se recoge la rotación adecuada y la rotación adicional al objeto
def get_quat_rot(el, t, q, l, angulo):

    el.rotate(q) #Vector el tras aplicarle la rotación del cuaternión q   
    
    el_prima = el.normalized()
    
    cos_ang = el_prima.dot(l)
    
    #El conseno debe estar entre -1 y 1
    if(cos_ang > 1):
        cos_ang = 1
    elif(cos_ang < -1):
        cos_ang = -1;

    ang = acos(cos_ang)

    #Rotacion adecuada
    sang2 = sin(ang/2)
    q2 = Quaternion((cos(ang/2),t[0]*sang2,t[1]*sang2,t[2]*sang2))
    
    #Rotacion adicional
    sang2 = sin(angulo/2) 
    q3 = Quaternion((cos(angulo/2),t[0]*sang2,t[1]*sang2,t[2]*sang2))
    
    qfinal = q3 @ q2
    
    return qfinal
         
########   buscar_tabla	##############
######## 
########   l    	Longitud total
########   pack 	Tabla de datos que indica para cada frame la distancia recorrida
########   Funcion que encuentra, mediante el metodo de la busqueda binaria, el frame al que le corresponde la longitud dada.
def buscar_tabla(l, pack):

    frames = pack[0]
    longitudes = pack[1]

    izq = 0
    der = len(longitudes) -1
    
    encontrado = -1
    medio = -1

    while ((der-izq) > 1):
        
        medio = int((izq+der)/2)
        
        if longitudes[medio] == l:
            encontrado = medio

        elif longitudes[medio] > l:
            der = medio

        else:
            izq = medio
    
    if(encontrado == -1):
        if(l > longitudes[medio]):
            ant = medio
            sig = medio+1
        else:
            ant = medio-1
            sig = medio
            
        if(sig > len(frames)-1):
            sig = 0
        elif(ant < 0):
            ant = 0
            
        devolver =sacar_u(longitudes[ant], longitudes[sig],l)
        frame_nuevo = lineal(frames[ant], frames[sig], devolver)
        
    else:        
        frame_nuevo = frames[medio]
        

    return frame_nuevo

########   sacar_u	##############
######## 
########   anterior 	distancia recorrida hasta el fotograma clave anterior
########   siguiente	distancia recorrida hasta el fotograma clave posterior
########   valor    	distancia recorrida hasta el fotograma clave actual     
def sacar_u(anterior, siguiente, valor):
    resultado = (valor-anterior)/(siguiente-anterior)
    
    return resultado
        
########   crear_tabla	##############
######## 
########   ini                  	Primer fotograma clave
########   fin                  	Ultimo fotograma clave
########   fotogramas_clave     	Vector de fotogramas clave
########   coordenadas          	Vector de posiciones de cada fotograma clave
########   accion               	Accion del objeto
########   interpolacion        	Metodo de interpolacion escogido
########   vel                  	Lista de velocidades obtenidas de cada fotograma clave
########   Funcion que crea una tabla: vector cuyo primer indice es un vector de fotogramas clave
########   y cuyo segundo indice es un vector de distancias. Correspondencia distancia - tiempo
def crear_tabla(ini, fin, fotogramas_clave, coordenadas, accion, interpolacion, vel):

    h = 1               #Frecuencia de marcas de longitud

    #Longitud inicial
    longitudes = [0]
    n_frame = [ini]
    L = 0
    
    pos = get_pos(fotogramas_clave, coordenadas, accion.name, 0, interpolacion, vel)

    for i in range(ini+1, fin+1, h):
        
        pos_ant = pos
        pos= get_pos(fotogramas_clave, coordenadas, accion.name, i, interpolacion, vel)
        
        d = (pos - pos_ant).magnitude
        L = L + d
        
        n_frame.append(i)
        longitudes.append(L)
    
    pack = []
    pack.append(n_frame)
    pack.append(longitudes)
    
    return pack    

################################## Creacion de avisos para el usuario sobre propiedades personalizadas #################################
####### Propiedad personalizada Velocidad
def draw(self, context):
    mensaje1 = "El nombre de la propiedad introducida para la velocidad modificada no coincide con ninguna propiedad del objeto seleccionado."
    mensaje2 = "Se ha calculado la velocidad constante y se ha creado una nueva 'Custom Properties' llamada 'prop' o 'prop.00x' para que pueda crear una curva marcando la longitud que desee que el objeto recorra en cada frame."
    mensaje3 = "Tras editar los valores de la 'Custom Property', debe introducir el nombre de la misma en el campo 'Nombre Propiedad'. (Si el nombre no ha sido editado, en ese caso, se debe introducir el nuevo nombre)."
    mensaje4 = "Recuerde modificar el parámetro 'Max.' de la 'Custom Property', si no se modifica, la longitud máxima que podrá recorrer el objeto será 1."
    mensaje6 = "Lea el manual para obtener más información."
    
    self.layout.label(text=mensaje1)
    self.layout.label(text=mensaje2)
    self.layout.label(text=mensaje3)
    self.layout.label(text=mensaje4)
    self.layout.label(text=mensaje6)
    
####### Propiedad personalizada Angulo de alabeo
def draw2(self, context):
    mensaje1 = "El nombre de la propiedad introducida para el ángulo no coincide con ninguna propiedad del objeto seleccionado."
    mensaje2 = "Se ha tomado ángulo=0 y se ha creado una nueva 'Custom Properties' llamada 'prop' o 'prop.00x' para que pueda crear una curva marcando el ángulo que desee que el objeto tenga en cada frame."
    mensaje3 = "Tras editar los valores de la 'Custom Property', debe introducir el nombre de la misma en el campo 'Nombre Propiedad'. (Si el nombre no ha sido editado, en ese caso, se debe introducir el nuevo nombre)."
    mensaje4 = "Recuerde modificar el parámetro 'Max.' de la 'Custom Property', si no se modifica, el ángulo máximo que podrá tomar el objeto será 1."
    mensaje6 = "Lea el manual para obtener más información."
    
    self.layout.label(text=mensaje1)
    self.layout.label(text=mensaje2)
    self.layout.label(text=mensaje3)
    self.layout.label(text=mensaje4)
    self.layout.label(text=mensaje6)
    
    
############################################################      Operador    ############################################################
class SimpleOperator(bpy.types.Operator):
    """Tooltip"""
    bl_idname = "object.simple_operator"
    bl_label = "Ejecutar"
    @classmethod
    def poll(cls, context):
        #Condiciones que se deben cumplir para que funcione el programa
        return len(bpy.context.selected_objects) is not 0 and len(bpy.context.selected_objects[0].animation_data.action.fcurves.find('location',index=0).keyframe_points) > 1 and (bpy.context.object.Eje != bpy.context.object.EjeLateral)
    
    def execute(self, context):
        main(context)
        
        return {'FINISHED'}
       
       
         
###########################################      Definición de las propiedades personalizadas      ###########################################
bpy.types.Object.Amplitud = bpy.props.FloatProperty(name = 'Amplitud', default = 0.01)
bpy.types.Object.Oscilacion = bpy.props.BoolProperty(name = 'Oscilacion', default = False)
bpy.types.Object.tipo_vel = bpy.props.EnumProperty(name ="tipo_vel", items = {("pred","Predeterminado","predeterminado"),("const","Constante", "constante"),("mod","Modificado","modificado")}, default = "pred")
bpy.types.Object.Metodo = bpy.props.EnumProperty(name ="Metodo", items = {("lin","Lineal","lineal"),("her","Hermite", "hermite"),("cat","Catmull_rom","catmull")}, default = "lin")
bpy.types.Object.Tension = bpy.props.FloatProperty(name="Tension", default = 0.2)
bpy.types.Object.Intervalos = bpy.props.IntProperty(name="Intervalos", default = 20)
bpy.types.Object.nombreProp = bpy.props.StringProperty(name = "nombreProp")   
bpy.types.Object.velocidadCte = bpy.props.FloatProperty(name = 'velocidadCte', default = 1)   
bpy.types.Object.Cuaterniones = bpy.props.BoolProperty(name = 'Cuaterniones', default = False)    
bpy.types.Object.Eje = bpy.props.EnumProperty(name ="Eje", items = {("X","X","X"),("Y","Y", "Y"),("Z","Z","Z")}, default = "X")
bpy.types.Object.EjeLateral = bpy.props.EnumProperty(name ="EjeLateral", items = {("X","X","X"),("Y","Y", "Y"),("Z","Z","Z")}, default = "Y")
bpy.types.Object.angAlabeo = bpy.props.BoolProperty(name = 'angAlabeo', default = False)
bpy.types.Object.nombrePropAng = bpy.props.StringProperty(name = "nombrePropAng")  



###########################################  Panel para configurar los parámetros gráficamente  ###########################################                                                                      
class Panel_interpolacion(bpy.types.Panel):
    """Creates a Panel in the scene context of the properties editor"""
 
    bl_label = "Interfaz interpolacion"
    bl_idname = "SCENE_PT_layout"
    bl_space_type = 'PROPERTIES'
    bl_region_type = 'WINDOW'
    bl_context = "object"
    def draw(self, context):
        layout = self.layout
        scene = context.object
        
        
        row = layout.row()
        row = self.layout.column(align=True)
    
    
        row.prop(scene, "Intervalos", text = "Intervalos")                  #Intervalos
        row.prop(scene, "Metodo", text = "Método")                          #Metodo
        if(bpy.context.object.Metodo == 'cat'):  
            row.prop(scene, "Tension", text = "Tension")               	    #Tension (si Catmull-Rom)
        row.prop(scene,"Oscilacion", text = "Oscilación")               	#Oscilacion
        if(bpy.context.object.Oscilacion == True):  
            row.prop(scene, "Amplitud", text = "Amplitud")                  #Amplitud (si hay oscilacion)
        row.prop(scene, "tipo_vel", text = "Tipo Velocidad")                #Tipo de velocidad seleccionada
        if(bpy.context.object.tipo_vel == 'const'): 
            row.prop(scene, "velocidadCte", text ="Velocidad Constante")    #Velocidad Constante
        if(bpy.context.object.tipo_vel == 'mod'): 
            row.prop(scene, "nombreProp", text ="Nombre propiedad:")         #Nombre propiedad de velocidad modificada
        row.prop(scene, "velocity", text = "Velocidad")                 	 #Velocidad
        row.prop(scene,"Cuaterniones", text = "Cuaterniones")                #Elegir orientacion por cuaterniones
        if(bpy.context.object.Cuaterniones == True):  
            row.prop(scene, "Eje", text = "Eje")                             #Eje principal
            row.prop(scene, "EjeLateral", text = "Eje Lateral")              #Eje lateral
            row.prop(scene,"angAlabeo", text = "Ángulo de alabeo")           #Angulo de alabeo
            if(bpy.context.object.angAlabeo == True):  
                row.prop(scene, "nombrePropAng", text ="Propiedad Ángulo:")  #Nombre de la propiedad de angulo de alabeo
        row.operator("object.simple_operator")                          	  #Boton de ejecutar

        
######## register() ########
########
######## Función que registra el panel para configurar las variables y su operador correspondiente
########
def register():
    bpy.utils.register_class(Panel_interpolacion)
    bpy.utils.register_class(SimpleOperator)
    
######## unregister() ########
########
######## Función que desregistra el panel para configurar las variables y su operador correspondiente
########    
def unregister():
    bpy.utils.unregister_class(Panel_interpolacion)
    bpy.utils.unregister_class(SimpleOperator)
if __name__ == "__main__":
    register()