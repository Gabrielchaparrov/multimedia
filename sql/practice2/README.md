# Practice 2 - Optimization of Oracle queries
This folder contains the solution for the exercices done in the seond practice of the subject **Database Management Systems**. 

## Base tables
The development of this practice requires the creation of 3 tables in the user's diagram as described below:

- TABLE **ACTORES**

| Column    | Type          | PK  | NN  | UNI | CHK | FK | COMMENTS |
|-----------|---------------|-----|-----|-----|-----|----|----------|
| OID       | NUMBER(10,0)  | YES |     |     |     |    |          |
| NOM       | CHAR(100)     |     | YES |     |     |    |          |
| SEXO      | CHAR(1)       |     | YES |     |     |    |          |

- TABLE **PELÍCULAS**

| Column    | Type          | PK  | NN  | UNI | CHK | FK | COMMENTS |
|-----------|---------------|-----|-----|-----|-----|----|----------|
| OID       | NUMBER(10,0)  | YES |     |     |     |    |          |
| TITULO    | CHAR(200)     |     | YES |     |     |    |          |
| ANYO      | CHAR(4,0)     |     | YES |     |     |    |          

- TABLE **ACTUACIÓN**

| Column    | Type          | PK  | NN  | UNI | CHK | FK | COMMENTS |
|-----------|---------------|-----|-----|-----|-----|----|----------|
| ACTOR     | NUMBER(10,0)  | YES |     |     |     |    |          |
| PELI      | NUMBER(10,0)  | YES |     |     |     |    |          |
| PAPEL     | CHAR(100)     | YES |     |     |     |    |          
