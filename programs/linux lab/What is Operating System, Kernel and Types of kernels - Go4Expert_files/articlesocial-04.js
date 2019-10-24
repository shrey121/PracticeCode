(function(d, s, id) {
  var js, fjs = d.getElementsByTagName(s)[0];
  if (d.getElementById(id)) return;
  js = d.createElement(s); js.id = id;
  js.src = "//connect.facebook.net/en_US/all.js#xfbml=1&appId=19238235718";
  fjs.parentNode.insertBefore(js, fjs);
}(document, 'script', 'facebook-jssdk'));
  (function() {
    var po = document.createElement('script'); po.type = 'text/javascript'; po.async = true;
    po.src = 'https://apis.google.com/js/plusone.js';
    var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(po, s);
  })();
  (function() {
    var po = document.createElement('script'); po.type = 'text/javascript'; po.async = true;
    po.src = '//platform.linkedin.com/in.js';
    var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(po, s);
  })();

!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0];if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src="//platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");

var authorSocialBar = {
    element: 'authorSocialBar',
    container: 'articlesocialcontrols',
    init: function () {
        element = authorSocialBar.element = document.getElementById('authorSocialBar');
        if (!element) return;
        authorSocialBar.scrollHeight = 300;//element.offsetHeight+10;
        elementTop = 0;
        do {
            elementTop += element.offsetTop || 0;
            element = element.offsetParent;
        } while (element);
        authorSocialBar.iniTop = elementTop;
        element = document.getElementById('ArticleContent');
        if (!element) return;
        authorSocialBar.articleHeight = elementContentHeight = element.offsetHeight;
        do {
            elementContentHeight += element.offsetTop || 0;
            element = element.offsetParent;
        } while (element);
        element = document.getElementById('ArticleSidebar');
        if (!element) return;
        elementSidebarHeight = element.offsetHeight;
        do {
            elementSidebarHeight += element.offsetTop || 0;
            element = element.offsetParent;
        } while (element);
        authorSocialBar.iniHeight = Math.max(elementSidebarHeight, elementContentHeight);
        authorSocialBar.element.offsetParent.style.height = authorSocialBar.articleHeight + 'px';
        if (elementContentHeight - elementSidebarHeight > 300) {
            if (window.addEventListener) {
                window.addEventListener('scroll', authorSocialBar.onScroll, false);
                window.addEventListener('unload', authorSocialBar.unload, false);
            } else if (window.attachEvent) {
                window.attachEvent('onscroll', authorSocialBar.onScroll);
                window.attachEvent('onunload', authorSocialBar.unload);
            }
            authorSocialBar.recalcheight();
        } else {
            authorSocialBar.element = null
        }
    },
    recalcheight: function () {
        element = document.getElementById('ArticleContent');
        if (!element) return;
        if (authorSocialBar.articleHeight < element.offsetHeight) {
            authorSocialBar.articleHeight = elementContentHeight = element.offsetHeight;
            do {
                elementContentHeight += element.offsetTop || 0;
                element = element.offsetParent;
            } while (element);
            authorSocialBar.iniHeight = elementContentHeight;
            authorSocialBar.element.offsetParent.style.height = authorSocialBar.articleHeight + 'px';
        }
    },
    unload: function () {
        authorSocialBar.element = null;
    },
    onScroll: function () {
        var pageY = (window.pageYOffset !== undefined) ? window.pageYOffset : (document.documentElement || document.body.parentNode || document.body).scrollTop;
        var t = pageY - authorSocialBar.iniTop;
        t = Math.min(t, authorSocialBar.articleHeight-300);
        if (t > 0 ) {
            if(!(pageY - authorSocialBar.iniHeight > -authorSocialBar.scrollHeight)) {
                authorSocialBar.element.style.top = '0px';
                authorSocialBar.element.style.position='fixed';
            } else {
                authorSocialBar.element.style.top = t + 'px';
                authorSocialBar.element.style.position='absolute';
            }
        } else if (t <= 0) {
            authorSocialBar.element.style.top = '0px';
            authorSocialBar.element.style.position='absolute';
        }
        authorSocialBar.recalcheight();
    }
}
YAHOO.util.Event.onDOMReady(authorSocialBar.init);