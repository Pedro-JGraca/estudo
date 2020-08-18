let amigo = {
    nome: "Jose",
    sexo: "M",
    peso:85.4,
    engordar(p){
        this.peso+=p;
    }
};
console.log("O " + amigo.nome + " tem " + amigo.peso + "kg");
amigo.engordar(10);
console.log("O " + amigo.nome + " tem " + amigo.peso + "kg");
