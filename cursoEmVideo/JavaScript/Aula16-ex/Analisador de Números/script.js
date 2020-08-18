var entrada = window.document.getElementById("entrada");
var caixa = document.getElementById("caixa");
var resultado = document.getElementById("resultado");
var array = [];

function adicionar() {
    let numero = Number(entrada.value);
    if(!numero) {
        window.alert("adicione um numero!");
    }
    else if ((numero<1)||(numero>100)) {
        window.alert("Numero alem dos limites");
    }
    else if (array.indexOf(numero)!=-1){
        window.alert("Numero " + numero + " já preenchido");
    }
    else {
        array.push(numero);
        let opt = window.document.createElement("option");
        opt.value = numero;
        opt.innerHTML = "valor " + numero + " adicionado";
        caixa.appendChild(opt);
        resultado.innerHTML="";
    }
    entrada.value= "";
    entrada.focus();
}

function finalizar () {
    if (array.length==0) {
        window.alert("adicione um numero!");
    }
    else {
        resultado.innerHTML="";
        resultado.innerHTML+="Ao todo, temos " + array.length + " numeros cadastrados.<br><br>";
        resultado.innerHTML+="O maior valor informado foi " + funcao("maior") + ".<br><br>";
        resultado.innerHTML+="O menor valor informado foi " + funcao("menor") + ".<br><br>";
        resultado.innerHTML+="Somando todos os valores temos " + funcao("soma") + ".<br><br>";
        resultado.innerHTML+="A media dos valores digitados é " + funcao("media") + " .<br><br>";
    }
}

function funcao(str) {
    let maior = 0;
    let menor = 101;
    let soma = 0;
    for (let i=0; i<array.length;i++){
        if (maior<array[i]){
            maior=array[i];
        }
        if (menor>array[i]){
            menor=array[i];
        }
        soma+=array[i];
    }
    switch (str) {
        case 'maior':
            return maior;
        case 'menor':
            return menor;
        case 'soma':
            return soma;
        case 'media':
            return soma/array.length;
        default:
            return -1;
    }
}

function limpar() {
    resultado.innerHTML="";
    //(caixa.options.length*2)
    for (let i = -1;i<(array.length+1);i++) {
        caixa.remove(i);
        //caixa.options[i].innerHTML = "";
    }
    array = [];

    for (i=0; i< caixa.options.length;i++) {
        limpar();
    }
    

}