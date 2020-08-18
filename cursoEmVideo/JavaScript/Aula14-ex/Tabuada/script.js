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
        const x = [];
        for (let i = 0; i<10;i++) {
            x[i] = caixa.options[i+1];
        }
        for (i=0;i<10;i++) {
            x[i].text = numero.value + "x"+(i+1)+" = " +  (numero.value*(i+1));
        }
    }

}

function limpar(){

    const x = [];
    for (let i = 0 ; i<10;i++) {
        x[i] = caixa.options[i+1];
    }
    for (i=0;i<10;i++) {
        x[i].text = "";
    }
}