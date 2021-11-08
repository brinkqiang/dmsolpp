module(..., package.seeall)

local interface = require("interface")

_M = {}
_M.pmap = {}
function _M.create_player()
    local p = interface.CPlayer.new()

    _M.pmap[p:GetObjID()] = p

    return p
end

function _M.find_player(id)
    local p = _M.pmap[id]

    return p
end

function _M.release_player(id)
    _M.pmap[id] = nil
end

return _M