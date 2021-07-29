module("interface", package.seeall)

local p = require("player")

p:Init()
p:NotChange()
p:OnChange()
print("[1]" .. GNextID())
print("[2]" .. p.NextID())
p:SetObjID(GNextID())
print("[3]" .. p:GetObjID())
p:SetHP(GNextID())
print("[4]" .. p:GetHP())
print("[5]" .. CPlayer.NextID())
