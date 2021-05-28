# React Flask MySQL Docker
Sistema de login com CRUD V0.0.0
A ideia é fazer um dashboard com 4 telas:
0 - Login
1 - SingUp



2 - Show DBS (without ADMIN,USERS)/ Create New DBs / Select DB / come back in 6,0
3 - Create/Drop TABLES in DB selected/ select TABLE / come back in 6,2,0
4 - SET structure in TABLE selected (set foreign keys) / PUT/DELETE DATA in Table / come back in 6,3,2,0


5 - show Users in the system

6 - white screen for selecting screens on the dashboard

7 - admin (acess whit 'localhost:3000/admin')
    Show Users and edit Users

Map:
0->1
0 -> 6
6 <-> 2 <-> 3 <-> 4
      2 <- 4
6 <-> 5

0 -> 7

0<-*
