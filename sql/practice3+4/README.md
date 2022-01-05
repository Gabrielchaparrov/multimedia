# Practice 3+4 - Control of transactions
This folder contains the solution for the exercices done in the third practice of the subject **Database Management Systems**. 

## Exercices

**EJ1.** Carry out the transactions, consisting of actions that will be carried out in an orderly manner, on the tables of each user's own schemes.

**EJ2.** Generate a database script that performs the transaction by running the tasks in the established order.

**EJ3.** Repeat transactions using 2 different types of isolation for transaction B: READ COMMITED and SERIALIZABLE.

**EJ4.** To carry out this exercise, 2 simultaneous sessions will be opened on the database. From each of the sessions the actions will be carried out, following the established time order and the corresponding session.

**EJ5.** To carry out this exercise, 2 simultaneous sessions will be opened on the database. From each of the sessions the actions will be carried out, following the established time order and the corresponding session. Comment on the differences / similarities between the two cases.

**EJ6.** Create a new EMPGRADE table (EMPNO, GRADE) to assign each employee (EMP) with their salary grade (SALGRADE). Build and execute the corresponding SQL statements to enter all employees in the EMPGRADE table and assign them their corresponding salary grade. In the event that an employee has a salary that does not correspond to any established grade, assign it the value 0 in the GRADE field. <br>
Create a PL / SQL procedure that performs the following actions on the database:
1. Create a new employee with the following characteristics:
a. Nombre: 8010
b. NAME: CAGE
c. JOB: ASSISTANT
2. Update the created employee (8010) with the values:
a. MGR: 8001
b. HIREDATE: 13/01/83
c. SAL: 3800
d. COMM: 100
e. DEPTNO: 50
3. Assign the newly created employee to salary grade number 4 with an insertion in the table EMPGRADE.
4. Check that the following conditions are met
a. Condition # 1: The assigned salary grade matches the employee's salary.
b. Condition # 2: The employee's salary is lower than his boss's.
5. If Condition # 2 is not met, undo the update and do it again with a salary 800 units lower than his boss.
6. In the event that Condition # 1 is not met, undo the insertion and assign in EMPGRADE the correct value.
7. Validate the transaction.
<br>

All these actions must be performed in the appropriate order to simplify the PL / SQL procedure and achieve the desired end result.