

//* Animated GIF w\ Caption for Game Modals
<figure><img src="/site/assets/files/1278/street-slicing.gif" alt="" width="640">
<figcaption>Dynamic slicing means your swordplay determines the cut placement and angle.</figcaption>
</figure>



<?php

//* Elvis Operator
$ubiTag = $card->game_tags->hasTitle("Ubisoft") ? true : false;
$or = $orToggle ? ' or ' : '-';

//* SelectOptions Field - If Option (Radio) Is Selected
$card = $page->card;

switch ($card->game_cover_tag) {
	case '1': $coverTag = '<span class="coverTag newTag">' . $card->game_cover_tag->title . '</span>'; break;
	case '2': $coverTag = '<span class="coverTag hotTag">' . $card->game_cover_tag->title . '</span>'; break;
	default: $coverTag = ''; break;
}

//* Sanitizer

// Camel Case
$gameName_cc = $sanitizer->camelCase($page->title);

//* Image Quality Switch Statement

switch ($card->img_quality) {
	case '1': $webpQ = 50; $jpgQ = 60; break;
	case '2': $webpQ = 65; $jpgQ = 65; break;
	case '3': $webpQ = 75; $jpgQ = 70; break;
	case '4': $webpQ = 85; $jpgQ = 80; break;
	default: $webpQ = 65; $jpgQ = 65; break;
}

$options = array( 'quality' => $jpgQ, 'webpAdd' => true, 'webpQuality' => $webpQ, 'sharpening' => 'none' );

//* Game Covers

