function verificar () {
    var Agora = new Date();
    var ano = Agora.getFullYear();
    var nasc = window.document.getElementById("txtAno");

    var res = window.document.getElementById("res");

    var res2 = window.document.getElementById("classeIdade");

    if (nasc.value.length == 0 || nasc.value > ano)  {
        res.innerHTML = "Verifique os dados";
        res2.innerHTML = "";
    }

    else {
        var Fgenenro= window.document.getElementsByName("radsex");

        var genenro = '';

        if (Fgenenro[0].checked) {
            genenro = "Outre";
        }
        if (Fgenenro[1].checked) {
            genenro = "Feminina";
        }
        if (Fgenenro[2].checked) {
            genenro = "Masculino";
        }
        else {
            genero = "falso";
        }

        var Faniversario=window.document.getElementsByName("radAni");
        
        var idade = ano-nasc.value;
        if (Faniversario[1].checked){
            idade--;
        }

        
        res.innerHTML = `Sua idade é de ${idade} anos e você é ${genenro}`;


        if (idade>0 && idade<12) {
            res2.innerHTML = "Você é uma criança.";
        }
        else if (idade < 18) {
            res2.innerHTML = "Você é uma Adolescente.";
        }
        else if (idade < 29) {
            res2.innerHTML = "Você é uma Jovem Adulta.";
        }
        else if (idade < 65) {
            res2.innerHTML = "Você é uma Adulta.";
        }
        else {
            res2.innerHTML = "Você é uma Idosa.";
        }
        
        if (Fgenenro[0].checked) {//outre
            if (idade>0 && idade<12) {
                res2.innerHTML = "Você é uma criança.";
            }
            else if (idade < 18) {
                res2.innerHTML = "Você é ume Adolescente.";
            }
            else if (idade < 29) {
                res2.innerHTML = "Você é ume Jovem Adulte.";
            }
            else if (idade < 65) {
                res2.innerHTML = "Você é ume Adulte.";
            }
            else {
                res2.innerHTML = "Você é ume Idose.";
            }
        }
        if (Fgenenro[1].checked) {//fem
            if (idade>0 && idade<12) {
                res2.innerHTML = "Você é uma criança.";
            }
            else if (idade < 18) {
                res2.innerHTML = "Você é uma Adolescente.";
            }
            else if (idade < 29) {
                res2.innerHTML = "Você é uma Jovem Adulta.";
            }
            else if (idade < 65) {
                res2.innerHTML = "Você é uma Adulta.";
            }
            else {
                res2.innerHTML = "Você é uma Idosa.";
            }
        }
        if (Fgenenro[2].checked) {//masc
            if (idade>0 && idade<12) {
                res2.innerHTML = "Você é uma criança.";
            }
            else if (idade < 18) {
                res2.innerHTML = "Você é um Adolescente.";
            }
            else if (idade < 29) {
                res2.innerHTML = "Você é um Jovem Adulto.";
            }
            else if (idade < 65) {
                res2.innerHTML = "Você é um Adulto.";
            }
            else {
                res2.innerHTML = "Você é um Idoso.";
            }
        }
    }

}