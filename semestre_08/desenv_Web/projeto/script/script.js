var img = document.getElementById("img");
var btn = document.getElementById("prev-button");
var btn1 = document.getElementById("next-button");
var i = 3;
var j = 1;

function up_img(){//atualizar as imagens
    img.src = "img/img"+j+".png";
    j++;
    if(j>3){
        j=1;
    }
}

btn.addEventListener("click", function(){//botão anterior
    img.src = "img/img"+i+".png";
    i--;
    if(i<1){
        i=3;
    }
    up_img();
});

btn1.addEventListener("click", function(){//botão próximo
    img.src = "img/img"+i+".png";
    i++;
    if(i>3){
        i=1;
    }
    up_img();
});

up_img();

