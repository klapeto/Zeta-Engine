---	This file is Part of Zeta Engine
--
--	The MIT License
--
-- Copyright (c) 2014 Ioannis G. Panagiotopoulos (AKA Klapeto)
--
-- Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
-- documentation files (the "Software"), to deal in the Software without restriction, including without limitation
-- the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
-- and to permit persons to whom the Software is furnished to do so, subject to the following conditions.
--
-- The above copyright notice and this permission notice shall be included in all copies or substantial
-- portions of the Software.
--
-- THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
-- INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
-- AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
-- DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
-- OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

local Dialog = {}	-- #Demo.Dialog

--------------------------------------------------------------------------------
-- Helper Functions for forming Dialogs
--
-- @module Demo.Dialog

--------------------------------------------------------------------------------
-- Reply type
--
-- @type Reply
-- @field [parent=#Reply] #string Text The text the Reply should have
-- @field [parent=#Reply] #string NextLine The next line to be shown when this is clicked

-------------------------------------------------------------------------------
-- Replies Table
--
-- @type Replies
-- @list <#Reply> The available Replies

--------------------------------------------------------------------------------
-- Dialog State
--
-- @type State
-- @field [parent=#State] #string Text What text should be shown
-- @field [parent=#State] #Replies Replies What replies are available

--------------------------------------------------------------------------------
-- Set of states
-- 
-- @type Dialog
-- @map <#string,#State> The Dialog States

--------------------------------------------------------------------------------
-- Creates a new Reply
--
-- @function [parent=#Demo.Dialog] NewReply
-- @param #string Text The text of the reply
-- @param #string NextLine Then next Line to be Shown
-- @return #Reply The New Reply
function Dialog.NewReply(Text,NextLine)
	return {Text = Text, NextLine = NextLine}
end

return Dialog
