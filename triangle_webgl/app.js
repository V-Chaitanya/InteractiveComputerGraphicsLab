var vertexShaderText=
[
'precision mediump float;',//precision of floating point variables can be hid ,mid ,low but we have considered medium
'',

'attribute vec2 vertPosition;',//attributes are input parameters 
'attribute vec3 vertColor;',//i/p paramater
'varying vec3 fragColor;',//o/p parameter
'',
'void main()',
'{',
'  fragColor = vertColor;',//we are setting this but not required for triangle
'  gl_Position = vec4(vertPosition, 0.0, 1.0);',//where on the actual rendering surface we want to draw that  vertex it then goes through rasteriser and then fragment shader 
'}'
].join('\n');
var fragmentShaderText =
[
'precision mediump float;',
'',
'varying vec3 fragColor;',//red green and blue 
'void main()',
'{',
'  gl_FragColor = vec4(fragColor, 1.0);',//suppose we want red color then we have to give vec4(1.0,0,0,1.0)
'}' 
].join('\n');




var InitDemo =function(){
console.log('this is working');
var canvas = document.getElementById('game-surface');//this brings the canvas in index as javascript object
var gl= canvas.getContext('webgl');
if (!gl) {
		console.log('I love to learn experimental-webgl');//WebGL not supported, falling back on experimental-webgl
		gl = canvas.getContext('experimental-webgl');
	}
	if (!gl) {
		alert('Your browser does not support WebGL');
	}

//canvas.width = window.innerWidth;
//canvas.height= window.innerHeight;
//gl.viewport=(0,0,innerWidth,innerHeight);
//default color will be black and it can be changed to get sonme color using gl.clearcolor function by setting red blue green valuees	
gl.clearColor(0.95,0.65,0.9,1.0);//this is just setting the color of the paint this is not actually performing any paint
gl.clear(gl.COLOR_BUFFER_BIT|gl.DEPTH_BUFFER_BIT);
var vertexShader = gl.createShader(gl.VERTEX_SHADER);//we use openGL to create a new shader objec and gl.VERTEX_SHADER is the type of shader that we want to use 
	var fragmentShader = gl.createShader(gl.FRAGMENT_SHADER);
	gl.shaderSource(vertexShader, vertexShaderText);
	gl.shaderSource(fragmentShader, fragmentShaderText);
	gl.compileShader(vertexShader);//for compilation  
	if (!gl.getShaderParameter(vertexShader, gl.COMPILE_STATUS))//for checking compilation errors of our shaders
	 {
		console.error('ERROR compiling vertex shader!', gl.getShaderInfoLog(vertexShader));//if the if condition returns true then we want to output an error to console.log with a information from the vertex shader
		return;
	}

    gl.compileShader(fragmentShader);
    if (!gl.getShaderParameter(fragmentShader, gl.COMPILE_STATUS)) {
		console.error('ERROR compiling fragment shader!', gl.getShaderInfoLog(fragmentShader));
		return;
	}
	// now we have fragment shader and vertex shader ready to use .(1st two stages of pipeline)
	//now we need to tell opengl that these are the two programs that we want to use together
	//we can do this by creating whats called a program in opengl and program shaders
		var program = gl.createProgram();
		gl.attachShader(program, vertexShader);
	    gl.attachShader(program, fragmentShader);
	    // now after compiling we need to link the programs together 
	    //not only checking for compiling errors we also need to check for linker errors
	    gl.linkProgram(program);
	    if (!gl.getProgramParameter(program, gl.LINK_STATUS)) {
		console.error('ERROR linking program!', gl.getProgramInfoLog(program));
		return;
	}
	//validating the program
	gl.validateProgram(program);
	if (!gl.getProgramParameter(program, gl.VALIDATE_STATUS)) {
		console.error('ERROR validating program!', gl.getProgramInfoLog(program));
		return;
	}
//now we have set the graphics card program now we need to set our vertices and create a triangle 
// in vertex shader we have one vector or attribute to set positions therefore we need to create a list of X and Y positions

var triangleVertices = 
	[ // X, Y,       R, G, B
		0.0, 0.5,    1.0, 0.0, 0.0,
		-0.5, -0.5,  0.0, 1.0, 0.0,
		0.5, -0.5,   0.0, 0.0, 0.5
		//0.5,0.5,0.5  1,0.5,0.5
	];
var triangleVertexBufferObject = gl.createBuffer();//this is the chunk of memory on the GPU ready to use
gl.bindBuffer(gl.ARRAY_BUFFER, triangleVertexBufferObject);//active buffer is array buffer
// now we need to specify the data on the active buffer
gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(triangleVertices), gl.STATIC_DRAW);// the reason for new float 32 bit array is because javascript stores the data as 64 bit but opengl is expecting a 32 bit 
//gl.STATIC_DRAW is means that we are sending the information from cpu memory to GPU memory
//now we need to inform the vertex shader that vert position is the attributes of X AND Y
var positionAttribLocation = gl.getAttribLocation(program, 'vertPosition');//getting the handle and 
var colorAttribLocation = gl.getAttribLocation(program, 'vertColor');
	gl.vertexAttribPointer(
		positionAttribLocation, // Attribute location
		2, // Number of elements per attribute
		gl.FLOAT, // Type of elements
		gl.FALSE,
		5 * Float32Array.BYTES_PER_ELEMENT, // Size of an individual vertex .Float32Array.BYTES_PER_ELEMENT this is because it should be properly interpreted by graphics card(although we know that it is 4bytes)
		0 // Offset from the beginning of a single vertex to this attribute
	); 
	gl.vertexAttribPointer(
		colorAttribLocation, // Attribute location
		3, // Number of elements per attribute
		gl.FLOAT, // Type of elements
		gl.FALSE,
		5 * Float32Array.BYTES_PER_ELEMENT, // Size of an individual vertex
		2 * Float32Array.BYTES_PER_ELEMENT // Offset from the beginning of a single vertex to this attribute
	);
	// now we need to enable attribute for use 
	gl.enableVertexAttribArray(positionAttribLocation);
     gl.enableVertexAttribArray(colorAttribLocation);
	gl.useProgram(program);
	gl.drawArrays(gl.TRIANGLES, 0, 3);




}; 
//function vertexShader(vertPosition,vertColor){
	//return{//main  funtion that vertex shader performs all the operations  
		//fragColor:vertColor;
		//gl_Position:[vertPosition.x,vertPosition.y,0.0,1.0]

	//};
//};
