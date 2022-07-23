module(..., package.seeall)

local interface = require("interface")

local player_mgr = require("player")

local player = player_mgr.create_player()

local p = player_mgr.find_player(player:GetObjID())

p:Init()
p:NotChange()
p.OnChange = function (self) print("OnChange in lua") end
p:OnChange()
print("[1]" .. interface.GNextID())
print("[2]" .. p.NextID())
p:SetObjID(interface.GNextID())
print("[3]" .. p:GetObjID())
p:SetHP(interface.GNextID())
print("[4]" .. p:GetHP())
print("[5]" .. interface.CPlayer.NextID())

player_mgr.release_player(p)

print("in lua.file player_mgr.create_player");
