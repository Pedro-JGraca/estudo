# React Flask MySQL Docker
<h1 align="center"> Sistema de login com CRUD V0.0.0 </h1>

A ideia é fazer um dashboard com 4 telas: Login (0), Register (1), DashBoard (2), Admin(3)

0 - Login
1 - Register New User


2 - white screen for selecting screens on the dashboard (DashBoard)

    2.1.0 - Show DBS (without ADMIN,USERS)/ Create New DBs / Select DB / come back in 2,0
    2.1.1 - Create/Drop TABLES in DB selected/ select TABLE / come back in 2.1.0,2,0
    2.1.2 - SET structure in TABLE selected (set foreign keys) / PUT/DELETE DATA in Table / come back in 2,2.1.1,0

    2.2 - Profile the USER

    2.3 - show Users in the system



3 - admin (acess whit 'localhost:3000/admin')
    Show/edit Users

Map the system:
0 -> 1
0 -> 2
     2 <-> 2.1.0 <-> 2.1.1 <-> 2.1.2 
     2 <- 2.1.2
     2 <-> 2.2
     2 <-> 2.3

0 -> 3

0<-*
