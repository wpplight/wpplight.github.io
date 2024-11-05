function domobile() {
    document.getElementsByClassName("backbuttonc").style.display = "none";
    document.getElementsByClassName("back-button").style.display = "block";
}
function ismobile()
{
    return /Mobi|Android/i.test(window.navigator.userAgent);
}
if (ismobile())
{
    domobile();
}