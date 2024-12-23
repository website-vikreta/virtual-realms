
//* NavMenu Toggle Btn */
function toggleMenu() {
	let navigation = document.querySelector("#mainNav");
	let toggleMenu = document.querySelector(".toggleMenu");
	let toggleX = document.querySelector(".toggleX");
	document.querySelector("body").classList.toggle("open-menu");
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
			if (typeof modals[index].style !== 'undefined'){
				modals[index].style.display = "none";
				if( document.querySelectorAll('.trailer-responsive video').length > 0 ){
					document.querySelectorAll('.trailer-responsive video').forEach(function (s_video) {
						s_video.pause();
					});
				}
			}
		}
	}
}

// When the user clicks anywhere outside of the modal, close it
window.onclick = function(event) {
	if (event.target.classList.contains('modal')) {
		for (var index in modals) {
			if (typeof modals[index].style !== 'undefined'){
				modals[index].style.display = "none";
				if( document.querySelectorAll('.trailer-responsive video').length > 0 ){
					document.querySelectorAll('.trailer-responsive video').forEach(function (s_video) {
						s_video.pause();
					});
				}
			}
		}
	}
}
document.addEventListener('click', function (event) {
    // Ensure the clicked element matches the selector
	if (event.target.closest('#faqs a.pagination-btn')) {
        event.preventDefault(); // Prevent default link behavior

        var p_this = event.target.closest('#faqs a.pagination-btn');

        if (p_this.classList.contains('active')) {
        	return false;
        }

        // Remove 'active' class from all pagination buttons
        var pagination = p_this.closest('.pagination');
        pagination.querySelectorAll('.pagination-btn').forEach(function (vbtn) {
        	vbtn.classList.remove('active');
        });

        // Show loader
        var faqs = p_this.closest('#faqs');
        var loaderWrap = faqs.querySelector('.vr-loader-wrap');
        loaderWrap.classList.add('active');

        // Add 'active' class to the clicked button
        p_this.classList.add('active');

        var ajax_url = window.location.origin + window.location.pathname +  p_this.getAttribute('href');

        // Make the AJAX request
        fetch(ajax_url, {
        	method: 'POST',
        	headers: {
        		'Content-Type': 'application/x-www-form-urlencoded',
        	},
        })
        .then(function (response) {
        	if (!response.ok) {
        		throw new Error('Network response was not ok');
        	}
        	return response.text();
        })
        .then(function (responseText) {
        	loaderWrap.classList.remove('active');

                // Update the content
        	var parser = new DOMParser();
        	var doc = parser.parseFromString(responseText, 'text/html');
        	var newContent = doc.querySelector('.faqs-inner').innerHTML;
        	faqs.querySelector('.faqs-inner').innerHTML = newContent;

                // Call load_faq function (ensure this function is defined elsewhere)
        	if (typeof load_faq === 'function') {
        		load_faq();
        	}
        })
        .catch(function (error) {

        	p_this.classList.remove('active');
        	var previousButton = p_this.previousElementSibling;
        	if (previousButton) {
        		previousButton.classList.add('active');
        	}
        	loaderWrap.classList.remove('active');
        });

        return false;
    }
    if (event.target.closest('.catWrapper .catBtns a')) {
    	var c_this = event.target.closest('.catWrapper .catBtns a');

    	if (c_this.classList.contains('active')) {
    		event.preventDefault();
    		return false;
    	}

    	var catWrapper = c_this.closest('.catWrapper');

        // Remove active class from all buttons
    	catWrapper.querySelectorAll('.catBtns button').forEach(function (vbutton) {
    		vbutton.classList.remove('active');
    	});

        // Add active class to loader
    	var vloaderWrap = catWrapper.querySelector('.vr-loader-wrap');
    	if (vloaderWrap) {
    		vloaderWrap.classList.add('active');
    	}

        // Add active class to the clicked button
    	var s_button = c_this.querySelector('button');
    	if (s_button) {
    		s_button.classList.add('active');
    	}

    	var ajax_url = window.location.origin + window.location.pathname + c_this.getAttribute('href');

        // Perform AJAX request
    	fetch(ajax_url, {
    		method: 'POST',
    		headers: {
    			'Content-Type': 'application/x-www-form-urlencoded',
    		}
    	})
    	.then(function (response) {
    		return response.text();
    	})
    	.then(function (html) {
    		if (vloaderWrap) {
    			vloaderWrap.classList.remove('active');
    		}
    		var parser = new DOMParser();
    		var doc = parser.parseFromString(html, 'text/html');
    		var newCards = doc.querySelector('.allGameCardsSection .cards');
    		var currentCards = document.querySelector('.allGameCardsSection .cards');
    		if (currentCards && newCards) {
    			currentCards.innerHTML = newCards.innerHTML;
    			load_all_images();
    		}
    	})
    	.catch(function (error) {
    		if (s_button) {
    			s_button.classList.remove('active');
    		}
    		var v_prevButton = c_this.previousElementSibling ? c_this.previousElementSibling.querySelector('button') : null;
    		if (v_prevButton) {
    			v_prevButton.classList.add('active');
    		}
    		if (vloaderWrap) {
    			vloaderWrap.classList.remove('active');
    		}
    	});
    	event.preventDefault();
    	return false;
    }
    if (event.target.closest('.hero-down-scroll button')) {
    	var v_targetElement = document.querySelector('#home-eventCards');
    	if (v_targetElement) {
    		var targetPosition = v_targetElement.offsetTop;
    		window.scrollTo({
    			top: targetPosition,
    			behavior: 'smooth'
    		});
    	}
    }
    if (event.target.closest('.cardInfo .trailerBtn')) {
    	var t_button = event.target.closest('.cardInfo .trailerBtn');
    	var trailerVideoLink = t_button.getAttribute('data-href');
    	var cardInfo = t_button.closest('.cardInfo');
    	var gameTitle = cardInfo.querySelector('.truncate h3').textContent;

    	var trailerModal = document.querySelector('.trailer-modal');
    	if (trailerModal) {
    		var videoElement = trailerModal.querySelector('video');
    		var modalHeader = trailerModal.querySelector('.modalHeader h3');

    		if (videoElement) {
    			videoElement.setAttribute('src', trailerVideoLink);
    		}

    		if (modalHeader) {
    			modalHeader.textContent = gameTitle;
    		}

    		trailerModal.style.display = 'block';
    	}
    }
});

setTimeout(function(){
	if( document.querySelectorAll('.event-card-slider').length > 0 ){
		new Swiper(".event-card-slider", {			
			spaceBetween: 1,
			breakpoints: {
				480: {
					slidesPerView: 1,					
				},
				500: {
					slidesPerView: 2,					
				},
				991: {
					slidesPerView: 2,					
				},
				1024: {
					slidesPerView: 2.5,					
				},
				1200: {
					slidesPerView: 3.5,					
				},
			}
		});
	} 
	if( document.querySelectorAll('.game-card-slider').length > 0 ){
		document.querySelectorAll('.game-card-slider').forEach(function (slider) {
			var desktopSlide = slider.getAttribute('data-slide-desktop');
			if( desktopSlide == undefined || desktopSlide == '' || desktopSlide == 0 ){
				desktopSlide = 3;
			}
			var tabletSlide = slider.getAttribute('data-slide-tablet');
			if( tabletSlide == undefined || tabletSlide == '' || tabletSlide == 0 ){
				tabletSlide = 2;
			}
			var mobileSlide = slider.getAttribute('data-slide-mobile');
			if( mobileSlide == undefined || mobileSlide == '' || mobileSlide == 0 ){
				mobileSlide = 1;
			}
			new Swiper(slider, {
				spaceBetween: 1,
				breakpoints: {
					480: {
						slidesPerView: mobileSlide,
						
					},
					500: {
						slidesPerView: mobileSlide,
						
					},
					768: {
						slidesPerView: tabletSlide,
						
					},
					1024: {
						slidesPerView: desktopSlide,
						
					},
				}
			});
		});
	}
},1000);

function load_faq(){
	if( document.querySelectorAll('div#faqs .faq h3').length > 0 ){
		const faqs = document.querySelectorAll('div#faqs .faq h3');
		faqs.forEach(function(faq) {
			faq.addEventListener('click', function() {
				const nextElement = faq.nextElementSibling;

				if (nextElement) {
                // Toggle the 'open' class
					nextElement.classList.toggle('open');

                // Ensure the max-height is dynamically set after the first click
					if (nextElement.classList.contains('open')) {
                    // Set max-height to the scrollHeight (the actual height of the content)
						nextElement.style.maxHeight = nextElement.scrollHeight + 'px';
					} else {
						nextElement.style.maxHeight = '0';
					}
				}
			});
		});
	}
}

load_faq(); 


function load_all_images(){
	let observer = new IntersectionObserver((entries, observer) => {
		entries.forEach(function (entry) {
			if (entry.intersectionRatio > 0 || entry.isIntersecting) {
				const image = entry.target;
				observer.unobserve(image);

				if (image.hasAttribute('src')) {
        // Image has been loaded already
					return;
				}

      // Image has not been loaded so load it
				const sourceUrl = image.getAttribute('data-src');
				image.setAttribute('src', sourceUrl);
				image.onload = () => {
        // Do stuff
				}

      // Removing the observer
				observer.unobserve(image);
			}
		});
	});

	document.querySelectorAll('img[data-src]').forEach((el) => {
		observer.observe(el);
	});
}

setTimeout(function() {
	load_all_images();
},100);