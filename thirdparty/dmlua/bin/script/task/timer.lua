-- lua script
module (..., package.seeall)

function main(role, taskid)
    print(role:GetName() .. " & " .. taskid)
    role:AcceptTask(taskid)
end

function main1(t1)

end

function main2(t1, t2)

end

function main3(t1, t2, t3)

end

function main4(t1, t2, t3, t4)

end

function main5(t1, t2, t3, t4, t5)

end
