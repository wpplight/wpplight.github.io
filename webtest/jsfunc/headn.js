function domobile() {
    let backButtonCs = document.getElementsByClassName("backbuttonc");
    let backButtons = document.getElementsByClassName("back-button");
    for (let i = 0; i < backButtonCs.length; i++) {
        backButtonCs[i].style.display = "none";
    }

    // 将所有 "back-button" 元素的 `display` 设置为 "block"
    for (let i = 0; i < backButtons.length; i++) {
        backButtons[i].style.display = "block";
    }
}
function ismobile()
{
    return /Mobile|Android|iPhone/i.test(navigator.userAgent);
}

if (ismobile())
{
    domobile();
}