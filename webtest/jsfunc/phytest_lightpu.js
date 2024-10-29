class youbiao {
    constructor() {
            this.left_1 = [],//度数
            this.left_2 = [],//分数
            this.left_3 = [],//秒数
            this.right_1 = [],
            this.right_2 = [],
            this.right_3 = [],
            this.pingjunl = 0,
            this.pingjunr = 0
    }
    pingjun() {
        this.pingjunl = this.left.reduce((sum, value) => sum + value, 0) / (this.left.length || 1);
        this.pingjunr = this.right.reduce((sum, value) => sum + value, 0) / (this.right.length || 1);
    }
    pingout() {
        console.log("pingjunl: " + this.pingjunl);
        console.log("pingjunr: " + this.pingjunr);
    }
}
var youbiao1 = new youbiao();
var youbiao2= new youbiao();

var left_n = 0;
var right_n = 0;

function is_need()
{
    if (document.getElementById("inputField").value != "" && document.getElementById("inputField2").value != "" && !isNaN(parseFloat(document.getElementById("inputField").value)) && !isNaN(parseFloat(document.getElementById("inputField2").value)))
        return true;
    
    return false;
}


function left_but_fu()
{
   
        if (is_need()) {
            document.getElementById("left_num").innerHTML = left_n;
            youbiao1.left_1.push(parseFloat(document.getElementById("inputField").value));
            youbiao1.left_2.push(parseFloat(document.getElementById("inputField2").value));
            left_n++;
            document.getElementById("left_num").innerHTML = left_n;
        }    
        else {
            alert("请输入数字！");
            }
    

   
}
function left_but_zh() {

    if (is_need()) {
        youbiao1.left_1.push(parseFloat(document.getElementById("inputField").value));
        youbiao1.left_2.push(parseFloat(document.getElementById("inputField2").value));
        left_n++;
        
    }
    else {
        alert("请输入数字！");
    }

}
function but_check() {
    if (left_n <= 3)
    {
        document.getElementById("left_num").innerHTML = left_n;
        if (left_n == 3) {
            document.getElementById("name").innerHTML ='‘+1’级左';
        }
    }
    else
    {
        document.getElementById("left_num2").innerHTML = left_n-3;
    }
    

    if(right_n <= 3)
    {
        document.getElementById("right_num").innerHTML = right_n;
    }
    else
    {
        document.getElementById("right_num2").innerHTML = right_n-3;
    }
}
        


function left_but()
{
  
    if (left_n >= 0 && left_n < 3)
        left_but_fu();
    else if (left_n >= 3 && left_n <6)
    {

    }

    but_check();
    
}




