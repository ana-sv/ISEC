$().ready(function () {
    iniciagaleria();
});



window.onresize = function (event) {
    $("#accordion-slider").remove();
    iniciagaleria();
};



function iniciagaleria() {
    $("#container-galeria").append('<ul id="accordion-slider"><li><img src="../img/imagem1.jpg" class="foto" alt="Image Title" ></li><li><img src="../img/imagem12.jpg" class="foto" alt="Image Title" ></li><li><img src="../img/imagem2.jpg" class="foto" alt="Image Title" ></li><li><img src="../img/imagem3.jpg" class="foto" alt="Image Title" ></li><li><img src="../img/imagem8.jpg" class="foto" alt="Image Title" ></li><li><img src="../img/imagem4.jpg" class="foto" alt="Image Title"></li></ul>');
    $("#container-galeria-hostel").append('<ul id="accordion-slider"><li><img src="../img/imagemA.jpg" class="foto" alt="Image Title" ></li><li><img src="../img/imagemB.jpg" class="foto" alt="Image Title" ></li><li><img src="../img/imagemC.jpg" class="foto" alt="Image Title" ></li><li><img src="../img/imagemD.jpg" class="foto" alt="Image Title" ></li><li><img src="../img/imagemE.jpg" class="foto" alt="Image Title" ></li><li><img src="../img/imagemF.jpg" class="foto" alt="Image Title"></li></ul>');
    if ($(window).width() > 900) {
        $('#accordion-slider').kwicks({
            event: 'click',
            eventClose: 'click',
            max: 800,
            spacing: 2
        });
    } else {
        $('#accordion-slider').kwicks({
            event: 'click',
            eventClose: 'click',
            max: 700,
            spacing: 2
        });
    }
}


function loginlogin() {
    if ($("#Utilizador").val() == "Ines" && $("#password").val() == "ines") {
        alert("Login efectuado com sucesso!");
        mostraconteudo();
    } else {
        escondeconteudo();
        alert("Dados invalidos");
        document.getElementById("login").reset();
    }
    return false;
}
function escondeconteudo() {
    $("#conteudoprotegido").html("Este conteúdo está protegido. Efectue Login para visualizar.");
}
function mostraconteudo() {
    $("form#loginlogin").hide();
    $("#conteudoprotegido").html('<img src="../img/login.jpg" class="foto" alt="Image Title" >');
}




function enviarformulario() {
    var resp;
    resp = confirm("Tem a certeza que pretende enviar o formulario?");
    if (resp == true) {
        alert("Formulario enviado com sucesso");
        document.getElementById("formulario").reset();
    } else {
        alert("Envio cancelado por escolha do utilizador");
    }
    return false;

}
