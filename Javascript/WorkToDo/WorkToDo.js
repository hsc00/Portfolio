var input = document.getElementById("getInput");
var enter = document.getElementById("enterButton");
var ul = document.querySelector("ul");

function createList(){	
	var li = document.createElement("li");
	
		if(input.value.startsWith("1"))
		{
			input.value = input.value.replace(/^(1-|1)/, "");
			if(getInputLength() < 1){return;}
			else li.classList.toggle("back_red");
		}
		if(input.value.startsWith("2"))
		{
			input.value = input.value.replace(/^(2-|2)/, "");
			if(getInputLength() < 1){return;}
			else li.classList.toggle("back_orange");
		}
		
	li.appendChild(document.createTextNode(input.value));
	ul.appendChild(li);
	input.value = "";
	
	var delButton = document.createElement("button");
	delButton.appendChild(document.createTextNode("X"));
	li.appendChild(delButton);
	delButton.addEventListener("click", deleteListItem);
	
	var checkButton = document.createElement("button");
	checkButton.appendChild(document.createTextNode("\u2713"));
	li.appendChild(checkButton);
	checkButton.addEventListener("click", turnInvisible);
	
	function deleteListItem(){li.classList.add("delete")}
	function turnInvisible(){li.classList.toggle("back_green")}
	
}

function getInputLength(){
	return input.value.length;
}


function enterPressed(event) {
	if(event.which === 13 && getInputLength() > 0){
			createList();
	}

}

input.addEventListener("keypress", enterPressed);
