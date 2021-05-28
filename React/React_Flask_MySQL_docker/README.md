# React Flask MySQL Docker
<h1 align="center"> Sistema de login com CRUD V0.0.0 </h1>
<p align="justify"> Um sistma CRUD complexo com manipulação de Tabelas a vontade com Login e ADMIN </p>

<h2 align="center"> Install </h2>
<p align="justify"> para que o sistema funcione veja abaixo</p>

<h2 align="center"> Sobre o Front </h2>
<p align="justify"> A ideia é fazer um dashboard com 4 telas: Login (0), Register (1), DashBoard (2), Admin(3)</p>

- [_] 0 Login 
- [_] 1 Register New User


- [_] 2 white screen for selecting screens on the dashboard (DashBoard)

    - [_] 2.1.0     Show DBS (without ADMIN,USERS)/ Create New DBs / Select DB
    - [_] 2.1.1     Create/Drop TABLES in DB selected/ select TABLE
    - [_] 2.1.2     SET structure in TABLE selected (set foreign keys) / PUT/DELETE DATA in Table
    - [_] 2.2       Profile the USER
    - [_] 2.3       show Users in the system



- [_] 3 admin (acess whit 'localhost:3000/admin')
<p align="justify">Show/edit Users</p>

<p align="justify">Map the system:</p>

- 0 -> 1
- 0 -> 2
    - 2 <-> 2.1.0 <-> 2.1.1 <-> 2.1.2 
    - 2 <- 2.1.2
    - 2 <-> 2.2
    - 2 <-> 2.3
- 0 -> 3
- 0 <- *

<h2 align="center"> Sobre o Back </h2>


<h2 align="center"> Sobre o Docker </h2>