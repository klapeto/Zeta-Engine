local Quest = require('Demo.QuestClass')("Έξω οι κότες!") -- Demo.QuestClass#Demo.QuestClass

do
	local Objective = require('SZLL.ObjectiveClass')("Βγάλε τις κότες έξω") -- SZLL.ObjectiveClass#SZLL.ObjectiveClass
	Objective.NSteps = 2
	Objective.Parent = Quest
	Objective.Shouts = {"Έξω! Έξω! Γρήγορα!","Ούστ!! Ούστ!!"}
	Objective.onActive = function (self)
		self.CollisionListener = Zeta.LuaListener(function(Invoker,Exit, Listener)
			if (Invoker:getName()=="Κότα" and Exit:getName()=="Teleport") then
				local Demo = require('Demo')
				Demo.World:getCurrentMap():removeObject(Invoker)
				Demo.Player:setTarget(nil)
				self:Step()
			end
		end
		,Zeta.WorldEvent.Type.Collision)
		self.InteractListener = Zeta.LuaListener(function(User1,User2, Listener)
			if (User1:getName()=="Κότα") then
				local fear = require('Demo.Abilities.Effects.Fear')
				if (User1:canReceiveEffect(fear)) then
					User1:setTarget(User2)
					require('Demo.Operations').Notify(Objective.Shouts[math.random(2)])
					User1:addEffect(fear:getNewEffect(User1,1))
				end
			end
		end
		,Zeta.WorldEvent.Type.Interact)
		local chi = require('Demo.Enemies.Chicken')
		chi:setIntroLine("Nill")
	end
	Objective.onCompleted = function (self)
		self.InteractListener:deactivate()
		self.InteractListener = nil
		self.CollisionListener:deactivate()
		self.CollisionListener = nil
		local chi = require('Demo.Enemies.Chicken')
		chi:setIntroLine("Intro1")
	end

	Objective.Out = "Χα! Τις έδειξα ποιος ειναι ο αρχηγός εδω!"

	Quest:addObjective(Objective)
end
Quest.Answer = {Text = "Γιατί έχετε τις κότες μέσα;", NextLine = "Kota1"}

Quest.QuestText = {
	Kota1 = {
		Text = "Ναι... Κανονικά έιναι έξω στο χωράφι, αλλα κάθε φορά που ανοίγει η πόρτα μπαίνουν μέσα! Τέρμα τελέιωσε! Θα πώ στον άνδρα μου να φτιάξουμε ένα κοτέτσι για να μην ξαναγίνει αυτο. Προς το παρών μπορείς να τις βγάλεις έξω;",
		Replies = {	{Text = "Πως να τις βγάλω έξω;", NextLine = "Kota2"} }
	},
	Kota2 = {
		Text = "Πλησίασέ τες και τρόμαξέ τες. Κάθε φορά που τις τρομάζεις πηγαίνουν εκεί που κοιτάς.",
		Replies = { {Text = "Οκ, έγινε!", NextLine = "Kota3"} }
	},
	Kota3 = {
		Text = "Συγνωμη που σε βάζω σε τέτοιο μπελά, αλλα σήμερα είναι η 6ή φορα που τις βγάζω έξω...",
		onInvoke = function()
			Quest:Activate()
		end
	},
	Kota4 = {
		Text = "Να 'σαι καλα παιδί μου! Μολις έρθει ο μπάρμπας εδώ, θα του πώ για το κοτέτσι.",
		onInvoke = function()
			Quest:Complete()
		end
	}
}

Quest.End = {Text = "Ουφ...!! Τις έβγαλα τις κότες...", NextLine = "Kota4"}

Quest.Description = "Η Μαρία θέλει να βγαλεις τις κότες έξω! Πήγαινε κοντα τους και κλίκαρε τες. Θα αρχισουν να τρέχουν μακρυα σου. Φροντισε να πανε προς την πορτα για να βγουν."

return Quest
