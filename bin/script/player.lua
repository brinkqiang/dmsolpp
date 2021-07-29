module("interface", package.seeall)

_M = {}

function _M.create_player()
    local p = CPlayer.new()
    return p
end

return _M