





Organisation can have multiple departments
All departments can have n numbers of docu
Documents type - medical records, employment records, compensation records

Users - SuperAdmin(All access), (Admins, modarators(only read access)) - configurable
C

1) Person - reset_passward(), view_document(id, catagory) 
    SuperAdmin - 
    Configuration : 

User:
    name
    id
    Configuration: FK
    state




Documnet(ABC):
    id:
    name:
    added_date:
    created_by: User FK
    Ddocument_type: ENUM(medical, employment, compensation)
    Department_type: MTM
    Organisation: 

Department:
    name
    id


permission:
    view_document: bool
    write_document: bool
    remove_user: bool
    add_user: bool


Configuration:
    Role_id: id
    permission: MTM
    department: MTM


Organisation:
    User: MTM
    name:
    id:








    






