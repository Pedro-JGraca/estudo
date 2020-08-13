function carregar() {
    var msg = window.document.getElementById("msg");
    var foto = window.document.getElementById("imagem");
    var agora = new Date();
    var hora = agora.getHours();
    msg.innerHTML = `Agora são ${hora} horas`;
    
    if (hora < 12 && hora>=6) {
        foto.src= "manha.png";
        document.body.style.background = "#e2cd9f";
        //boa manha
    }
    else if (hora >= 12 && hora <= 18) {
        foto.src= "tarde.png";
        document.body.style.background = "#b9846f";
        //boa tarde
    }
    else {
        foto.src= "noite.png";
        document.body.style.background = "#515154";
        //boa noite
    }
}

