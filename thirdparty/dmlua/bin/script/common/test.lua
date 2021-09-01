-- lua script
module (..., package.seeall)

function main_vector(vec)

    vec:push_back('world')
    
    print(vec:size())

    for i=0,vec:size()-1,1 do print(vec[i]) end

end
function main()
    local role = CreateRole();
    role:SetName("Jerry2020")

    print("Player Name = " .. role:GetName())
    print("PlayerID = " .. role:GetObjID())

    ReleaseRole(role)
end
