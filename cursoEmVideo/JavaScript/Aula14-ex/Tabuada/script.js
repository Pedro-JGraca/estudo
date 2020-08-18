//alert( 'ola!');
let numero = document.getElementById("entrada");
let caixa = document.getElementById("caixa");

function update() {

    let titulo = caixa.options[0];
//    var res = document.getElementById("res");
    if(!numero.value) {
        //res.innerHTML += titulo.text;
        titulo.text = "Coloque um valor";
        limpar();
    }
    else {
        //res.innerHTML += titulo.text;
        titulo.text = "Calculará tabuada de " + numero.value ;
        limpar();
    }

}
function tabuada() {
    let titulo = caixa.options[0];
    if(!numero.value) {
        titulo.text = "Coloque um valor valido";
        limpar();
    }
    else if ((numero.value>50)||(numero.value<-50)) {
        titulo.text = "Coloque um numero entre 51 e -51";
        limpar();
    }
    else {
        titulo.text = "Tabuada de " + numero.value;
        let x1 = caixa.options[1];
        let x2 = caixa.options[2];
        let x3 = caixa.options[3];
        let x4 = caixa.options[4];
        let x5 = caixa.options[5];
        let x6 = caixa.options[6];
        let x7 = caixa.options[7];
        let x8 = caixa.options[8];
        let x9 = caixa.options[9];
        let x10 = caixa.options[10];


        x1.text = numero.value + "x1 = " +  (numero.value*1);
        x2.text = numero.value + "x2 = " +  (numero.value*2);
        x3.text = numero.value + "x3 = " +  (numero.value*3);
        x4.text = numero.value + "x4 = " +  (numero.value*4);
        x5.text = numero.value + "x5 = " +  (numero.value*5);
        x6.text = numero.value + "x6 = " +  (numero.value*6);
        x7.text = numero.value + "x7 = " +  (numero.value*7);
        x8.text = numero.value + "x8 = " +  (numero.value*8);
        x9.text = numero.value + "x9 = " +  (numero.value*9);
        x10.text = numero.value + "x10 = " +  (numero.value*10);

    }

}

function limpar(){
    let x1 = caixa.options[1];
    let x2 = caixa.options[2];
    let x3 = caixa.options[3];
    let x4 = caixa.options[4];
    let x5 = caixa.options[5];
    let x6 = caixa.options[6];
    let x7 = caixa.options[7];
    let x8 = caixa.options[8];
    let x9 = caixa.options[9];
    let x10 = caixa.options[10];


    x1.text = "";
    x2.text = "";
    x3.text = "";
    x4.text = "";
    x5.text = "";
    x6.text = "";
    x7.text = "";
    x8.text = "";
    x9.text = "";
    x10.text = "";
}