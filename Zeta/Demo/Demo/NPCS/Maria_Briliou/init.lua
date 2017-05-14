local Npc = require('Demo.Npc')

--------------------------------------------------------------------------------
-- Maria Briliou NPC
-- Barba Brilio's Wife
--
-- @module Maria_Briliou
-- @extends Demo.Npc#Demo.Npc

local Maria = Npc("Demo/NPCS/Maria_Briliou/Class.xml",500,200)

do
	local states = {
		Intro = {
			Text = "Γειά και καλως ήρθες στην φάρμα μας! Κάθησε να φάμε, έχω φτιάξει φαγητό αν θές. Αν θές πάρτο όλο, εγώ έφαγα. Ο άνδρας μου δεν πρόκειτε να φάει, άρα χαμενο θα πάει. Φοβάμαι οτι θα πάθει ασυτία που δεν τρώει τίποτα...",
			Replies = {
				{Text = "Τι έχει o άνδρας σου;", NextLine = "Quest1"},
				{Text = "Πως τα περνάτε εδώ;", NextLine = "Quest2"}
			}

		},
		Quest1 = {
			Text = "Έχει προβλήματα στα χωράφια, αλλά δεν μου λέει τι.",
			Replies = {{Text = "Θα πάω να ρωτήσω τον άνδρα σου", NextLine = "Quest1_2"}}
		},
		Quest1_2 = {
			Text = "Ναι πήγαινε ρώτησέ τον. Ελπίζω να σου πει τι τρέχει...",
			Replies = {},
			onInvoke = function (params)
				local Brilios = require('Demo.NPCS.Barba_Brilios')
				Brilios:addQuest(require('Demo.Quests.SnakeInvasion'))
			end
		},
		Quest2 = {
			Text = "Τα ίδια, όπως καθημερινά. Εγώ ασχολούμαι με το νοικοκυριό, και ο ανδρας μου δουλεύει στα χωράφια μας. Κάθε Σαββατοκύριακο πηγαίνουμε στο χωριό στο πανιγύρι να ξεσκάσουμε.",
			Replies = {}
		},
		Final = {
			Text = "Ο άνδρας μου είναι χαρούμενος ξάνα! Τι έκανες;!",
			Replies = {}
		}
	}


	Maria:setStates(states)
	Maria:setIntroLine("Intro")
	Maria:addQuest(require('Demo.Quests.ChickensOut'))
end

function Maria:Reset()
	Maria:setIntroLine("Intro")
end


return Maria
