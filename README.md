# anscom-shell
The shell version of anscom pypi extension.
my logic notes including issues faced:
<img width="1879" height="1023" alt="image" src="https://github.com/user-attachments/assets/4980ed1d-6ed1-44aa-956e-bae8d553be8d" />
<img width="1293" height="838" alt="image" src="https://github.com/user-attachments/assets/e155cbb4-5603-4047-b3c0-76663b3b7e37" />
<img width="1914" height="1059" alt="image" src="https://github.com/user-attachments/assets/b31637db-af5d-4fe2-a3ff-ef432d8f5bf9" />

the issue is ok with the non permissible files but when it comes to the /root files it create a permision denied error which can block the scan. solution: use std::filesystem::directory_options::skip_permision_denied.
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/ea1125a6-bbe3-4f00-9373-ae2c5833aa95" />


# security skips: wherever the the g++ compiler sees that the directory/folder exists while the itterator goes on it will skip the one which are not accessible. 
eg: linux root folder.
<img width="1903" height="1043" alt="image" src="https://github.com/user-attachments/assets/7e9f8643-b735-4f37-90ec-42500aedbfc8" />

# the compiler has a specific type std::error_code.
<img width="1894" height="1036" alt="image" src="https://github.com/user-attachments/assets/7c454117-fc88-4a7c-98e4-e502a316e78b" />
