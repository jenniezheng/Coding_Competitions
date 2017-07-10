process.stdin.resume();
process.stdin.setEncoding('ascii');

var input_stdin = "";
var input_stdin_array = "";
var input_currentline = 0;

process.stdin.on('data', function (data) {
    input_stdin += data;
});

process.stdin.on('end', function () {
    input_stdin_array = input_stdin.split("\n");
    main();    
});

function readLine() {
    return input_stdin_array[input_currentline++];
}

/////////////// ignore above this line ////////////////////

function getWays(arr, num, targetSum){
    console.log("HI");
    var ways=0;
    var sum=0;
    if(arr.length<num)
        return 0;
    for(var i=0; i<num; i++)
        sum+=arr[i];
    if(sum==targetSum)
        ways++;
    for(var i=0; i<arr.length-num; i++){
        sum-=arr[i];
        sum+=arr[i+num];
        if(sum==targetSum)
            ways++;
    }
    return ways;
}

function main() {
    var n = parseInt(readLine());
    s = readLine().split(' ');
    s = s.map(Number);
    var d_temp = readLine().split(' ');
    var d = parseInt(d_temp[0]);
    var m = parseInt(d_temp[1]);
    var result = getWays(s, d, m);
    Console.log(result);

}
