(function () {
    function loadAds() {
        var c1 = "<iframe frameborder=\"0\" marginwidth=\"0\" marginheight=\"0\" scrolling=\"no\" width=\"728\" height=\"90\" src=\"http://www.go4expert.com/ads/adLogoGAM.html\"></iframe>";
        var c2 = "<iframe frameborder=\"0\" marginwidth=\"0\" marginheight=\"0\" scrolling=\"no\" width=\"300\" height=\"250\" src=\"http://www.go4expert.com/ads/sidebarSponsorGAMATF.html\"></iframe>";
        var c3 = "<iframe frameborder=\"0\" marginwidth=\"0\" marginheight=\"0\" scrolling=\"no\" width=\"300\" height=\"600\" src=\"http://www.go4expert.com/ads/sidebarSponsorGAMBTF.html\"></iframe>";
        var c4 = "<h2><a href=\"http://www.facebook.com/go4expert\" rel=\"nofollow\" target=\"_blank\">Find Us On Facebook</h2><iframe frameborder=\"0\" marginwidth=\"0\" marginheight=\"0\" scrolling=\"no\" width=\"288\" height=\"240\" src=\"http://www.go4expert.com/ads/fb_widget.html\"></iframe>";
        var adLogo = document.getElementById('AdLogo');
        if (adLogo != null && adLogo.offsetWidth>0) adLogo.innerHTML = c1;
        var sidebarsponsor1 = document.getElementById('sidebarsponsor1');
        if (sidebarsponsor1 != null) sidebarsponsor1.innerHTML = c2;
        var sidebarsponsor2 = document.getElementById('sidebarsponsor2');
        if (sidebarsponsor2 != null) sidebarsponsor2.innerHTML = c3;
        var fb_widget = document.getElementById('fb_widget');
        if (fb_widget != null) fb_widget.innerHTML = c4;
    }
    var oldonload = window.onload;
    window.onload = (typeof window.onload != 'function') ? loadAds : function () {
        oldonload();
        loadAds();
    };
})();
