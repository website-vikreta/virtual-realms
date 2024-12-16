
<?php

	function socialBtn($href, $icon) {
		echo "<span class='icon'>
			<a href='{$href}' target='_blank'>
				<i class='ph-duotone ph-{$icon}-logo'></i>
			</a>
		</span>";
	}

	function navLink($url, $title, $icon) {
		echo "<li>
			<a href='{$url}'>
				<span class='icon'>
					<i class='ph-duotone ph-{$icon}'></i>
				</span>
				<span class='title'>{$title}</span>
			</a>
		</li>";
	}

	function listChildrenTree($children) {
		foreach ($children as $page):
			$url = $page->url;
			$pageIcon = $page->page_icon;
			$pageTitle = $page->title;
			navLink($url, $pageTitle, $pageIcon);
		endforeach;
		navLink('#subscribe', 'Subscribe', 'tray-arrow-down');
		navLink('#faqs', 'FAQs', 'question');
	}

?>

<header>

	<div id="adminBtns">
		<?= $modules->isInstalled('AdminLinksInFrontend') ? $modules->get('AdminLinksInFrontend')->render() : ''; ?>
	</div>

	<nav id="mainNav">

		<div id="sideLogo">
			<?php include("./includes/global/logo-lg.inc"); ?>
		</div>

		<ul id="navLinks">

			<?php
				$icon = $pages->get('/')->page_icon;
				navLink('/', 'Home', $icon);
				listChildrenTree($pages->get('/')->children);
			?>
		</ul>

		<div id="bottomWrapper">
			<div id="socialBtns">
				<?php
					if($facebookUrl != "") { socialBtn($facebookUrl, 'facebook'); }
					if($instagramUrl != "") { socialBtn($instagramUrl, 'instagram'); }
					if($youtubeUrl != "") { socialBtn($youtubeUrl, 'youtube'); }
					if($linkedinUrl != "") { socialBtn($linkedinUrl, 'linkedin'); }
					if($twitterUrl != "") { socialBtn($twitterUrl, 'twitter'); }
					if($tiktokUrl != "") { socialBtn($tiktokUrl, 'tiktok'); }
				?>
			</div>
			<a href="tel:<?=$phoneNumber?>">
				<div id="phoneInfo">
					<span class="icon">
						<i class="ph-duotone ph-phone"></i>
					</span>
					<span class="title"><?=$phoneNumber?></span>
				</div>
			</a>
		</div>

		<div id="gradient"></div>

	</nav>

	<div id="pageHead">
		<div id="mobileLogo">
			<a href="/"><?php include("./includes/global/logo-lg.inc"); ?></a>
		</div>
	</div>

	<div class="toggle toggleMenu" onclick="toggleMenu()">
		<i class="ph-duotone ph-sidebar-simple"></i>
	</div>

	<div class="toggle toggleX active" onclick="toggleMenu()">
		<i class="ph-duotone ph-x-square"></i>
	</div>

</header>
