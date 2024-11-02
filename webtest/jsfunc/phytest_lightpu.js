var ub = 0.000084;
var c = [];
var t = [0, 0, 0];
var n = 0;

function new_check() {
    
    document.getElementById("num").innerHTML = n;
    document.getElementById("name").innerHTML = n+1;
    if (n >= 3) {
        document.getElementById("end_div").style.display = "block";
        
    }
    else
    {
        document.getElementById("end_div").style.display = "none";
        document.getElementById("name").innerHTML = n + 1;
    }

}

function push()
{
    if (n < 3) {
        for (var i = 0; i < 3; i++) {
            if (document.getElementById(`inputField${i + 1}`).value != "")
            {
                t[i] = parseFloat(document.getElementById(`inputField${i + 1}`).value);
                
            }
                
            else {
                t[i] = 0;
            }
            
        }
        var sum = t[0] + t[1] / 60 + t[2] / 3600;
        sum = sum / 180 * Math.PI/2;
        c.push(sum);
        n++;
        new_check();
        for (var i = 0; i < 3; i++) {
            
             document.getElementById(`inputField${i + 1}`).value = "";

        }
    }
    else {
        alert("你已经输入了三组数据了，不能再输入了！");
    }

}

function pop_button()
{
    if (n > 0)
    {
        n--;
        c.pop();
        new_check();
    }
    else {
        alert("你还没有输入数据！");
    }
}

function calculate()
{
    var s="";
    for (var i = 0; i < n; i++)
    {
        s +=c[i].toFixed(6)+",";
    }
    document.getElementById("result_t").innerHTML = s;
    var sum = (c[0] + c[1] + c[2]) / 3;
    document.getElementById("result_d").innerHTML = sum.toFixed(6);
    var r =Math.sin(sum);
    document.getElementById("result_w").innerHTML = (r/300).toFixed(9);
    var ua = 0;
    for(var i=0;i<n;i++)
    {
        ua += Math.pow(c[i]-sum,2);
    }
    ua = Math.sqrt(ua / 6) * 1.32;
    document.getElementById("result_a").innerHTML = ua.toFixed(6);
    document.getElementById("result_b").innerHTML = (ub).toFixed(6);
    var u = Math.sqrt(ua * ua + ub * ub);
    document.getElementById("result_e").innerHTML = u.toFixed(6);
    var u_ = Math.sqrt(Math.pow(1 / Math.tan(sum), 2) * u * u + 0.001 * 0.001);
    document.getElementById("result_f").innerHTML = u_.toFixed(9);
    z = u_*r/300;
    document.getElementById("result_g").innerHTML = z.toFixed(9);
    

    
}




