module("interface", package.seeall)

local player_mgr = require("player")

local player = player_mgr.create_player()

local p = player_mgr.find_player(player:GetObjID())

p:Init()
p:NotChange()
p.OnChange = function (self) print("OnChange in lua") end
p:OnChange()
print("[1]" .. GNextID())
print("[2]" .. p.NextID())
p:SetObjID(GNextID())
print("[3]" .. p:GetObjID())
p:SetHP(GNextID())
print("[4]" .. p:GetHP())
print("[5]" .. CPlayer.NextID())

player_mgr.release_player(p)
