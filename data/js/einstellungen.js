$(document).ready(function(){
    $('SELECT[name="currentLang"]').on('change', function(){
        var selectedValue = $(this).val();
        document.languageImage.src = "img/c_LangDE_24.jpg";
        if(selectedValue == 'de'){
            document.languageImage.src = "img/c_LangDE_24.jpg";
        }
        else if(selectedValue == 'en'){
            document.languageImage.src = "img/c_LangEN_24.jpg";
        }
    });
});
$(document).ready(function(){
    $('SELECT[name="currentTheme"]').on('change', function(){
        var selectedValue = $(this).val();
        document.themeImage.src = "img/Theme_24.jpg";
        if(selectedValue == 'color'){
            document.themeImage.src = "img/Theme_24.jpg";
        }
        else if(selectedValue == 'blackwhite'){
            document.themeImage.src = "img/ThemeBW_24.jpg";
        }
        else if(selectedValue == 'outline'){
            document.themeImage.src = "img/ThemeOutline_24.jpg";
        }
    });
});