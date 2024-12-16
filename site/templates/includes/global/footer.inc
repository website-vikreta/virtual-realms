
<?php

	function footSocialBtn($href, $icon) {
		echo "<span class='icon'>
			<a href='{$href}' target='_blank'>
				<i class='ph-duotone ph-{$icon}-logo'></i>
			</a>
		</span>";
	}

?>


<!-- //* Footer -->

<footer role="contentinfo">

	<section class="mainContent">

		<div id="bigFooter">

		<div id="footerInner">
			<div id="footLogo">
				<a href="/">
					<?php include("./includes/global/logo-lg.inc"); ?>
				</a>
			</div>

			<?php

				$footerSecs = $pages->get("/footer-links/")->children();

				foreach ($footerSecs as $sec):
			?>

			<div class="group">
				<span class='icon'>
					<i class='ph-duotone ph-<?= $sec->page_icon ?>'></i>
				</span>
				<h2><?= $sec->title ?></h2>
				<?= $sec->footer_links ?>
			</div>

			<?php endforeach; ?>

			<div class="group">
				<span class='icon'>
					<i class='ph-duotone ph-thumbs-up'></i>
				</span>
				<h2>Connect</h2>
				<div id="footerConnect">
				<?php
					if($facebookUrl != "") { footSocialBtn($facebookUrl, 'facebook'); }
					if($instagramUrl != "") { footSocialBtn($instagramUrl, 'instagram'); }
					if($youtubeUrl != "") { footSocialBtn($youtubeUrl, 'youtube'); }
					if($linkedinUrl != "") { footSocialBtn($linkedinUrl, 'linkedin'); }
					if($twitterUrl != "") { footSocialBtn($twitterUrl, 'twitter'); }
					if($tiktokUrl != "") { footSocialBtn($tiktokUrl, 'tiktok'); }
				?>
				</div>
			</div>

		</div>
		</div>

		<div id="footerBottom">
			<small>
				<div>&copy; <time>2025</time> Virtual Realms LLC</div>
				<div id="pw">
				Powered by <a href='https://processwire.com'>ProcessWire</a>
				</div>
			</small>
		</div>

	</section>

</footer>



