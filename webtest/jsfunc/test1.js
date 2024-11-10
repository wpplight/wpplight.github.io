function xishua() {
    document.getElementById('momo').src = 'imagefile/dragon.png';
    document.getElementById('demo').innerHTML = '联系个蛋啊，真以为我能负责啊？';
    document.getElementById('but1').style.display = 'none';
    document.getElementById('but2').style.display = 'block';
}

function check_a()
{
    if (confirm('你不同意？😂'))
    {
        document.getElementById('but2').style.display = 'none';
    }
    else
    {
        check_a();
    }
}

function check_b()
{
    if (confirm('不许再点了！🤞😊'))
    {
        document.getElementById('but2').style.display = 'none';
    }
    else
    {
        check_a();
    }
}

function handleloadClick() { 
window.location.href = 'load.html';
}
function handleloadClick1() {
    window.location.href = 'webtest/load.html';
}

const but1 = document.getElementById('dengl1');
if (but1)  but1.addEventListener('click', handleloadClick1);
const but = document.getElementById('dengl');
if(but) but.addEventListener('click', handleloadClick);


