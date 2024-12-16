

<div class="cardWrapper">

	<div class="cards">

		<?php

		$defaultGameDuration = '15 min. - 3 hrs.';
		$defaultAge = 6;

		$count = 0;

		foreach ($cards as $card):

			$count++;

			$gameName = $card->title;
			$gameName_cc = $sanitizer->camelCase($gameName);
			$age = $card->game_age;
			$minPlayers = $card->game_min_players;
			$maxPlayers = $card->game_max_players;
			$orToggle = $card->game_or_toggle;
			$freeRoam = $card->game_free_roam;
			$gameLength = $card->game_duration;

			switch ($pageTitle) {
				case "VR Library": $cover = $card->card_cover; break;
				default: $cover = $card->ubi_cover == null ? $card->card_cover : $card->ubi_cover; break;
			}

			/* Sets the max number of players to the number of HMDs if the max number of players is greater than the number of HMDs. */
			$maxPlayers = $maxPlayers > $hmdCount ? $hmdCount : $maxPlayers;

			/* Sets the difficulty value for the card */
			switch ($card->game_difficulty) {
				case '1': $difficulty = 'Easy'; break;
				case '2': $difficulty = 'Normal'; break;
				case '3': $difficulty = 'Challenging'; break;
				case '4': $difficulty = 'Very Hard'; break;
				case '5': $difficulty = 'Adjustable'; break;
			}

			/* Sets the age value for the card */
			$age = $age == "" || $age <= 6 ? $age = $defaultAge. "+" : $age = $age. "+";
			$length = $gameLength == "" ? $defaultGameDuration : $gameLength;

			//*** NUMBER OF PLAYERS ***/

			/* Toggles between using '-' and 'or'*/
			$or = $orToggle ? ' or ' : ' - ';

			/* Sets the player(s) value for the card based on min/max players  */
			switch ($maxPlayers) {
				case '1': 	$players = '<i class="ph-duotone ph-user"></i>
							<span class="label">1 player</span>'; break;
				default: {
					if ($maxPlayers > $minPlayers) {
						switch ($maxPlayers) {
							case 2: $players = '<i class="ph-duotone ph-users"></i>
							<span class="label">' . $minPlayers . $or . $maxPlayers . ' players</span>'; break;
							default: $players = '<i class="ph-duotone ph-users-three"></i>
                            <span class="label">' . $minPlayers . $or . $maxPlayers .' players</span>'; break;
						}
					} else {
						switch ($maxPlayers) {
							case 2: $players = '<i class="ph-duotone ph-users"></i>
							<span class="label">' . $minPlayers . ' players</span>'; break;
							default: $players = '<i class="ph-duotone ph-users-three"></i>
                            <span class="label">' . $minPlayers .' players</span>'; break;
						}
					}
				}
			}

			//*** GAME COVERS ***/

			/* Sets the cover ratio for the game cover image */
			switch ($freeRoam) {
				case true: {
					$coverRatio = 'normal';
					$altName = $gameName . " free-roam VR"; break;
				}
				default: {
					switch ($ubi) {
						case true: {
							$coverRatio = 'wide';
							$altName = $gameName . " Ubisoft VR escape room"; break;
						};
						case false: {
							$coverRatio = 'normal';
							$altName = $gameName . " room-scale VR"; break;
						}
					}
				}
			}

			/* Sets the image quality for the game cover image */
			switch ($card->img_quality) {
				case '1': $webpQ = 55; $jpgQ = 65; break;
				case '2': $webpQ = 70; $jpgQ = 70; break;
				case '3': $webpQ = 80; $jpgQ = 75; break;
				case '4': $webpQ = 90; $jpgQ = 85; break;
				default: $webpQ = 70; $jpgQ = 70; break;
			}

			/* Sets the image options for the game cover image */

			/* Set $forceCovers to true to force new cover images to be generated */
			$newCovers = false;

			if ($newCovers == true) {
				$options = array( 'quality' => $jpgQ, 'webpAdd' => true, 'webpQuality' => $webpQ, 'sharpening' => 'none', 'forceNew' => true );
			} else {
				$options = array( 'quality' => $jpgQ, 'webpAdd' => true, 'webpQuality' => $webpQ, 'sharpening' => 'none' );
			}

			/* Generates game cover image based on aspect ratio */
			switch ($coverRatio) {
				case 'normal': $gameCover = $cover->size(460, 215, $options); break;
				case 'wide': $gameCover = $cover->size(860, 540, $options); break;
			}

			$gameTags = $card->game_tags;
			$gameTagsHyphen = "";

			/* Game tags */
			foreach ($gameTags as $tag):
				$gameTagsHyphen.= " " . $sanitizer->hyphenCase($tag->title);
			endforeach;

			/* Game cover tags */
			foreach ($gameTags as $tag):
				if ($tag->title == 'Editors Choice') {
					$coverTag = '<span class="coverTag eChoiceTag">Editor\'s Choice</span>'; break;
				} elseif ($tag->title == 'Hot') {
					$coverTag = '<span class="coverTag hotTag">Hot</span>'; break;
				} elseif ($tag->title == 'New') {
					$coverTag = '<span class="coverTag newTag">New</span>'; break;
				} { $coverTag = ''; }
			endforeach;

		?>

		<section class="gameCard card card<?= $count ?> <?= $gameTagsHyphen ?> ">

			<div class="cardCover">
				<picture class="cardThumb">
					<source type="image/webp" srcset="<?= $gameCover->webp->url ?>" />
					<img loading="lazy" data-type="jpg" data-src="<?= $gameCover->url ?>" alt=" <?= $altName ?> game cover."/>
				</picture>
				<?= $coverTag ?>
			</div>

			<section class="cardInfo">
				<div class="truncate">
					<h3><?= $gameName; ?></h3>
				</div>
				<div class="topInfo">
					<div class="length">
						<i class='ph-duotone ph-clock-countdown'></i>
						<span class='label'><?= $length ?></span>
					</div>
					<div class="difficulty">
						<i class='ph-duotone ph-puzzle-piece'></i>
						<span class='label'><?= $difficulty ?></span>
					</div>
				</div>
				<div class="bottomInfo">
					<div class="players"><?= $players; ?></div>
					<div class="age">
						<i class='ph-duotone ph-baby-carriage'></i>
						<span class='label'><?= $age ?></span>
					</div>
				</div>
				<div class="catTags">
					<?php
						$tagCount = 0;
						foreach ($gameTags as $tag):
							while ($tagCount < 3) {
								if ($tag->title == 'Single-Player' || $tag->title == 'Multi-Player' || $tag->title == "Editors Choice" || $tag->title == "Hot" || $tag->title == "New" || $tag->title == "Ubisoft" || $tag->title == "Offline Multiplayer" || $tag->title == "Offline" || $tag->title == "Standalone Server" || $tag->title == "Free-Roam" || $tag->title == "Room-Scale") {
									break;
								} else {
									$tagCount++;
									echo '<span class="tag tag' . $tagCount . '">' . $tag->title . '</span>'; break;
								}
							}
						endforeach;
					?>
				</div>
				<div class="btns">
					<button href="#<?= $gameName_cc; ?>Modal" class="modalBtn btn" type="button" >
						Details
					</button>
					<button class="trailerBtn btn" type="button">Trailer</button>
				</div>
			</section>

		</section>

		<?php
			// Breaks out of the loop if the max number of cards has been reached (as long as not a Ubisoft card)
			if ($count === $maxCards && $ubi == false) { break; }
			endforeach;
		?>

	</div>

</div>
