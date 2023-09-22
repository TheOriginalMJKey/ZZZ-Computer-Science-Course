# Разрешите исполнять для владельца, писать для группы и владельца и читать для всех.

for files:
chmod g+w,u+wx,a+r file_name
 
for folders:
chmod -R g+w,u+wx,a+r folder_name
