
//* NavMenu Toggle Btn */
function toggleMenu() {
	let navigation = document.querySelector("#mainNav");
	let toggleMenu = document.querySelector(".toggleMenu");
	let toggleX = document.querySelector(".toggleX");
	navigation.classList.toggle("active");
	toggleX.classList.toggle("active");
	toggleMenu.classList.toggle("active");
}


//* Card Modal */

// Get the button that opens the modal
var btn = document.querySelectorAll("button.modalBtn");

// All page modals
var modals = document.querySelectorAll('.modal');

// Get the <span> element that closes the modal
var spans = document.getElementsByClassName("close");

// When the user clicks the button, open the modal
for (var i = 0; i < btn.length; i++) {
btn[i].onclick = function(e) {
		e.preventDefault();
		modal = document.querySelector(e.target.getAttribute("href"));
		modal.style.display = "block";
	}
}

// When the user clicks on <span> (x), close the modal
for (var i = 0; i < spans.length; i++) {
	spans[i].onclick = function() {
		for (var index in modals) {
		if (typeof modals[index].style !== 'undefined') modals[index].style.display = "none";
		}
	}
}

// When the user clicks anywhere outside of the modal, close it
window.onclick = function(event) {
    if (event.target.classList.contains('modal')) {
		for (var index in modals) {
		if (typeof modals[index].style !== 'undefined') modals[index].style.display = "none";
		}
    }
}


