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

/////////////// process stdin ////////////////////

function createEdges(numEdges, edges_array){
	for(; numEdges>0; numEdges--) {
    	var edge=readLine().split(" ");
    	nodeStart=parseInt(edge[0]);
    	nodeEnd=parseInt(edge[1]);
    	edges_array.push([nodeStart, nodeEnd]);
    	edges_array.push([nodeEnd, nodeStart]);
    }
}

function getConnectedNodes(node, edges_array){
	connected=[]
	for(var index=0; index<edges_array.length; index++)
		if (edges_array[index][0]==node)
			connected.push(edges_array[index][1]);
	return connected;
}

function hasAlreadyVisited( node, alreadyVisited ){
	for(var index=0; index<alreadyVisited.length; index++)
		if (alreadyVisited[index]==node)
			return true;
	return false;
}

function getDistances(startNode, edges_array, numNodes){
	var distances=[];
	for( var index=0; index<=numNodes; index++){
		distances.push(-1);
	}

	var visited=[startNode];
    var queue=[[startNode,0]];
    while(queue.length!=0){
    	currDistance=queue[0][1];
    	distances[queue[0][0]]=currDistance;
    	//console.log("currently on node ", queue[0][0], " with distance", currDistance);
    	connectedNodes=getConnectedNodes(queue[0][0],edges_array);
    	//console.log("connected nodes ",connectedNodes);
    	for(var index=0; index<connectedNodes.length; index++){
    		if (!hasAlreadyVisited(connectedNodes[index],visited)){
    			queue.push([connectedNodes[index],currDistance+1]);
    			visited.push(connectedNodes[index]);
    		}
    	}
    	queue.shift();
    }
    distances.shift();
    return distances;
}

function processQuery(){
	var line_array=readLine().split(" ");
    var numNodes=parseInt(line_array[0]);
    var numEdges=parseInt(line_array[1]);
    var edges_array=[];
    createEdges(numEdges,edges_array);
    var startNode=parseInt(readLine());
    var distances=getDistances(startNode,edges_array, numNodes)
    var result="";
    for(var index=0; index<distances.length; index++){
	    if (index==startNode-1)
		    continue;
		ans=distances[index];
		if(ans!=-1)
			ans*=6;
	    result+=ans.toString()+" ";
    }
    return result;

}

function main() {
	var numQueries = parseInt(readLine())
    for(; 0< numQueries ; numQueries--)
	    console.log(processQuery());
}