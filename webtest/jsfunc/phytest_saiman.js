var end = [];
var data = [];
var s = "";
var I;
var n = 0;

function new_num()
{
    document.getElementById("num").innerHTML = n;
    document.getElementById("canshu").innerHTML = 4 - n;
    document.getElementById("num1").innerHTML = n;
    document.getElementById("canshu1").innerHTML = 4 - n;
}

function tu()
{
    document.getElementById("saimanliucheng").style.display = "block";
    document.getElementById("btn").style.display = "none";
    document.getElementById("btn2").style.display = "block";
}

function notu()
{
    document.getElementById("saimanliucheng").style.display = "none";
    document.getElementById("btn").style.display = "block";
    document.getElementById("btn2").style.display = "none";
}

function showin_zuobiao()
{
    document.getElementById("yuanshi").style.display = "block";
    document.getElementById("btn4").style.display = "none";
    document.getElementById("btn3").innerHTML = "关闭";
    new_num();
    document.getElementById("btn3").onclick = function () {
        
        document.getElementById("yuanshi").style.display = "none";
        document.getElementById("btn4").style.display = "block";
        document.getElementById("btn3").innerHTML = "输入坐标位置";
        document.getElementById("btn3").onclick = showin_zuobiao;
    };
}

function showin_chazhi() {
    document.getElementById("chazhi").style.display = "block";
    document.getElementById("btn3").style.display = "none";
    document.getElementById("btn4").innerHTML = "关闭";
    new_num();
    document.getElementById("btn4").onclick = function () {

        document.getElementById("chazhi").style.display = "none";
        document.getElementById("btn3").style.display = "block";
        document.getElementById("btn4").innerHTML = "输入算好的差值";
        document.getElementById("btn4").onclick = showin_chazhi;
    };
}
function is_need(a) {
    if (a!= "" &&  !isNaN(parseFloat(a)))
        return true;

    return false;
}
function add_zuobiao()
{
    var input = [];
    var m;
    for (var i = 1; i <= 8; i++)
    {
        m = document.getElementById(`inputField${i}`).value;
        if (is_need(m))
        {
            input.push(parseFloat(m));
        }
        else
            {
            alert("请全部输入数字！");
            return;
        }

    }
    if (input.length == 8)
    {   data.push([]);
        for (var i = 0; i < 4; i++)
        {
            data[n].push(input[7 - i]- input[i]);
            s += parseFloat(input[7 - i]- input[i] ).toFixed(3) + " ";
        }
        n++;
        new_num();
        for (var i = 1; i <= 8; i++) {
            document.getElementById(`inputField${i}`).value = "";
        }
        document.getElementById("zhanshi").innerHTML = "计算好差值为" + s;
        s = "";

    }
    else
    {
        alert("请全部输入数字！");
    }
    if (n == 4)
    {
        document.getElementById("yes").style.display = "block";
    }
}

function add_chazhi()
{
    var input = [];
    var m;
    for (var i = 1; i <= 4; i++)
    {
        data.push([]);
        m = document.getElementById(`chazhi${i}`).value;
        if (is_need(m))
        {
            data[n].push(parseFloat(m));
        }
        else
            {
            alert("请全部输入数字！");
            data.pop();
            return;
        }

    }
    for (var i = 1; i <=4; i++) {
        document.getElementById(`chazhi${i}`).value = "";
    }
    n++;
    new_num();
    if (n == 4) {
        document.getElementById("yes1").style.display = "block";

    }
}

function pop_chazhi()
{
    if (n > 0)
    {
        end.pop();
        n--;
        new_num();
    }
    else
    {
        alert("没有数据可以删除！");
    }
}

function chuli()
{
    document.getElementById("chuli").style.display = "block";
}

function pop_zuobiao()
{
    if (n > 0)
    {
        data.pop();
        n--;
        new_num();
    }
    else
    {
        alert("没有数据可以删除！");
    }
}

function end_ans()
{
    var ch = "";
    m = document.getElementById("LI").value;
    if (is_need(m)) { 
        I=parseFloat(m);
    }
    var da = "";
    for (var i = 0; i < 4; i++)
    {
        for (var j = 0; j < 4; j++)
            {
            da += data[i][j].toFixed(3) + " ";
        }
        da += "<br>";
    }
        document.getElementById("sihe").innerHTML = "差值表格为" + da;
    for (var i = 0; i < 4; i++)
    {
        end.push((data[0][i] + data[1][i] + data[2][i] + data[3][i]) / 4);
        ch+=end[i].toFixed(3) + " ";
    }
    document.getElementById("pingjun").innerHTML = "所求得平均为：" + ch;
    var ans = 2 * Math.PI * 3 / 0.9 / 2 / I;
    ans=ans*(end[0]*end[0]-end[2]*end[2])/(end[1]*end[1]-end[3]*end[3]);
    document.getElementById("result").innerHTML = "结果为：" + ans;
    ans = Math.abs(ans - 1.76) / 1.76 * 100;
    document.getElementById("error").innerHTML = "相比于理论值，误差为：" + ans+ "%";
}
