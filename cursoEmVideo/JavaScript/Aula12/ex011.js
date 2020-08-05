var idade = 22;
console.log(`Você tem ${idade} anos.`);

if (idade < 16) {
    console.log("Seu voto é Proibido");
}
else if (idade < 18 && idade>65) {
    console.log("Seu voto é Opcional");
}
else {
    console.log("Seu voto é obrigatorio");
}
   