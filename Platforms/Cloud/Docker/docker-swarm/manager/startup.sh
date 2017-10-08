sudo apt-get update && sudo apt-get dist-upgrade -y && sudo apt-get autoremove -y \
&& sudo apt-get install \
    linux-image-extra-$(uname -r) \
    linux-image-extra-virtual -y \
&& sudo apt-get install \
    apt-transport-https \
    ca-certificates \
    curl \
    software-properties-common -y \
&& curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add - \
&& sudo add-apt-repository \
   "deb [arch=amd64] https://download.docker.com/linux/ubuntu \
   $(lsb_release -cs) \
   stable" \
&& sudo apt-get clean \
&& sudo apt-get update \
&& sudo apt-get install docker-ce -y \
&& sudo usermod -aG docker $USER
