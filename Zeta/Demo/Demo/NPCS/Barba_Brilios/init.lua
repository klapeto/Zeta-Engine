
local Npc = require('Demo.Npc')

--------------------------------------------------------------------------------
-- Barba Brilios NPC
-- A farm owner from Fine Forest
--
-- @module Barba_Brilios
-- @extends Demo.Npc#Demo.Npc


local Mparbas = Npc("Demo/NPCS/Barba_Brilios/Class.xml",5248,8128)

do
	local states = {
		Intro1 = {
			Text = "Γειά χαρά κόρη μου! Πέρνα! Η Μαρία είναι μέσα στο σπίτι!",
			Replies = {{Text = "Εντάξει Κύριε Μπρίλιο!",NextLine = "Quest1"}}
		},
		Quest1 = {
			Text = "Πήγαινε, πήγαινε! Η πόρτα είναι δίπλα!",
			Replies = {}
		},
		Intro2 = {
			Text = "Τα 'πατε με τη Μαρία ε;",
			Replies = {{Text = "Ναί, έμαθα οτι έχετε προβληματα...", NextLine = "Quest2"}}
		},
		Quest2 = {
			Text = "Σου είπε ε; Ναι... Βασικά δεν μπορώ να μπώ στα χωράφια μου γιατί εχουν φίδια!!",
			Replies = {{Text = "Δεν βλέπω κάτι περίεργο;", NextLine = "Quest2_1"}}
		},
		Quest2_1 = {
			Text = "Μάλλον δεν τα έχεις δεί για αυτό τα λές αυτα... Το μικρότερο απο αυτά είναι σαν μεγαλόσωμος σκύλος!",
			Replies = {{Text = "Σοβαρά;!;!!", NextLine = "Quest2_2"}}
		},
		Quest2_2 = {
			Text = "Ναί! Και δεν τολμάω να μπώ στα χωράφια μου να μαζέψω τίποτα! Ντρέπομαι να πώ στην Μαρία τι συμβαίνει γιατί θα με πάρει στο ψιλο γαζί..",
			Replies = {{Text = "Θα φροντίσω εγώ για τα φίδια.", NextLine = "Quest2_3"}}
		},
		Quest2_3 = {
			Text = "Αλήθεια; Να 'σαι καλά κοπέλα μου! Αν το κάνεις αυτό, θα σε αναμείψω!",
			Replies = {},
			onInvoke = function()
				local demo = require('Demo')
				--demo.Player:addQuest(require("Demo.Quests.SnakeInvasion"))
			end
		},
		Quest_complete = {
			Text = "Τα κατάφερες; Πως; ... Έφερες τον Ομοσπονδιακό Στρατό; Τέλος πάντων, δεν έχει σημασία!  Σε ευχαριστώ πάρα πολύ! Πάρε αυτό σαν κάτι για την ευνομοσύνη μου!",
			Replies = {},
			onInvoke = function ()
				Mparbas:setIntroLine("Intro3")
			end
		},
		Intro3 = {
			Text = "Γειά σου Ευτυχία! Είσαι πάντα ευπρόσδεκτη στην φάρμα μου!",
			Teplies = {}
		}
	}

	Mparbas:setStates(states)
	Mparbas:setIntroLine("Intro1")
end

function Mparbas:Reset()
	Mparbas:setIntroLine("Intro1")
end

return Mparbas

