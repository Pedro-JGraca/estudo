# React Flask MySQL Docker
<h1 align="center"> Sistema de login com CRUD V0.0.0 </h1>
<p align="justify"> Um sistma CRUD complexo com manipulação de Tabelas a vontade com Login e ADMIN </p>
<p align="justify"> A ideia é fazer um dashboard com 4 telas: Login (0), Register (1), DashBoard (2), Admin(3)</p>

- [] 0 Login 
- [] 1 Register New User


- [] 2 white screen for selecting screens on the dashboard (DashBoard)

    - 2.1.0 Show DBS (without ADMIN,USERS)/ Create New DBs / Select DB
    - 2.1.1 Create/Drop TABLES in DB selected/ select TABLE
    - 2.1.2 SET structure in TABLE selected (set foreign keys) / PUT/DELETE DATA in Table
    - 2.2 - Profile the USER
    - 2.3 - show Users in the system



- 3 admin (acess whit 'localhost:3000/admin')
<p align="justify">Show/edit Users</p>

Map the system:
0 -> 1
0 -> 2
     2 <-> 2.1.0 <-> 2.1.1 <-> 2.1.2 
     2 <- 2.1.2
     2 <-> 2.2
     2 <-> 2.3

0 -> 3

0<-*
