-- lua script
module (..., package.seeall)

function AcceptTask(objID, taskID, ret)
    local role = FindRole(objID)
    if role == nil then
        ret.value = -1
        print("AcceptTask FindRole = nil")
        return
    end
    print("==================================")
    print("Player Name = " .. role:GetName())
    print("PlayerID = " .. role:GetObjID())
    print("AcceptTask taskID = " .. taskID)

    if role:AcceptTask(taskID) then
        ret.value = 0
    	print("AcceptTask ret = " .. math.ceil(ret.value))
    else
        ret.value = -1
    	print("AcceptTask ret = " .. math.ceil(ret.value))
    end

    print("###################################")
end

function FinishTask(objID, taskID)
    local role = FindRole(objID)
    if role == nil then
        print("FinishTask FindRole = nil")
        return
    end

    print("==================================")
    print("Player Name = " .. role:GetName())
    print("PlayerID = " .. role:GetObjID())
    print("FinishTask taskID = " .. taskID)
    print("==================================")
    role:FinishTask(taskID)
end
