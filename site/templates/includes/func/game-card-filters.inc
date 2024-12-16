<?php

	// CARD FILTERS
	$cardFilters = $section->card_filters;
	$cardFiltersNeg = $section->card_filters_neg;

	if ($cardFilters == "") {
		$cardFilter = $cardFiltersNeg == "" ? $cardFilter = '' : $cardFilter = 'game_tags!=' . $cardFiltersNeg;
	} else {
		$cardFilter = $cardFiltersNeg == "" ? $cardFilter = 'game_tags=' . $cardFilters : $cardFilter = 'game_tags!=' . $cardFiltersNeg . ',' . 'game_tags=' . $cardFilters;
	}

	// Sets $ubi variable to true for Ubisoft cards
	$ubi = $headingHyph == "ubisoft" ? true : false;

	$cards = $pages->get("/vr-games-experiences/")->children->find("$cardFilter, sort=-release_date");

?>