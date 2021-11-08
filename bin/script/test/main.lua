module(..., package.seeall)
local interface = require("interface")

function dowork(p)
    p:Init()
    p:NotChange()
    return 1
end