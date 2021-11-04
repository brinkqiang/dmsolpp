module("interface", package.seeall)
module(..., package.seeall)

function dowork(p)
    p:Init()
    p:NotChange()
    return 1
end