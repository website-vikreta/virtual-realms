<div id="cardModals">

	<?php

		$cards = $pages->get("/vr-games-experiences/")->children->find($cardFilter);

		foreach ($cards as $card) :

			$gameName = $card->title;
			$gameName_cc = $sanitizer->camelCase($gameName);
			$age = $card->game_age . "+";
			$length = $card->game_duration . " min.";
			$details = $card->details;
			$playSpace = $card->game_play_space;
			$features = $card->game_features;
			$maxPlayers = $card->game_max_players;
			$dev = $card->game_developers->title != '' ? $card->game_developers->title : '';

			/* Sets the max number of players to the number of HMDs if the max number of players is greater than the number of HMDs. */
			$maxPlayers = $maxPlayers > $hmdCount ? $hmdCount : $maxPlayers;

			if ($features != "") {
				$featuresInfo = '<div class="features">
				<h4 class="featHead">Features</h4>' .
				$features . '</div>';
			} else { $featuresInfo = ''; }

			if ($playSpace != "") {
				$playSpaceInfo = '<div class="playSpace">
				<h4 class="spaceHead">Play Space</h4>' .
				$playSpace . '</div>';
			} else {
				$playSpace = $maxPlayers == 1 ? '7 sqft.' : '7 sqft. per player';
				$playSpaceInfo = '<div class="playSpace">
				<h4 class="spaceHead">Play Space</h4>
				<p>' . $playSpace . '</p>' . '</div>';
			}

			$gameTags = $card->game_tags;
			$gameTagsHyphen = "";

			/* Creates a hyphenated string of game tags */
			foreach ($gameTags as $tag): $gameTagsHyphen.= " " . $sanitizer->hyphenCase($tag->title); endforeach;

			/* Sets the modal header */
			$modalHead = $card->modal_heading != '' ? '<h4 class="topH4">' . $card->modal_heading . '</h4>' : '<h4 class="hide">Overview</h4>';

	?>

	<div id="<?= $gameName_cc; ?>Modal" class="modal">
		<div class="modal-content">
			<div class="modalHeader">
				<span class="close">×</span>
				<h3><?= $gameName; ?></h3>
			</div>
			<div class="modal-body">
				<?= $modalHead; ?>
				<div class="details"><?= $details; ?></div>
				<?= $featuresInfo; ?>
				<?= $playSpaceInfo; ?>
			</div>
			<div class="catTags">
					<?php
						$tagCount = 0;
						foreach ($gameTags as $tag):
							while ($tagCount != '') {
								if ($tag->title == 'Single-Player' || $tag->title == 'Multi-Player' || $tag->title == 'Hot' || $tag->title == 'Editors Choice' || $tag->title == 'New' || $tag->title == "Ubisoft" || $tag->title == "Standalone Server" || $tag->title == "Offline Multiplayer" || $tag->title == "Offline" || $tag->title == "Internet Required" || $tag->title == "Free-Roam" || $tag->title == "Room-Scale") {
									break;
								} else {
									echo '<span class="tag">' . $tag->title . '</span>'; break;
								}
							}
						endforeach;
					?>
				</div>
		</div>
	</div>

	<?php endforeach; ?>

</div>