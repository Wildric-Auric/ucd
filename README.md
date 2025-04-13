

<p align="center">
    <img src= "https://github.com/user-attachments/assets/61fdd2ce-aab0-454c-a5f5-c897afbc5a62"
        height="300">
</p>
<p align="center">
    <a href="mailto:wildric.auric@gmail.com" alt="Email">
        <img src="https://img.shields.io/badge/Gmail-D14836?logo=gmail&logoColor=white" /></a>
    <a href="https://github.com/Wildric-Auric/ucd/edit/main/README.md#linux" alt="Linux">
        <img src="https://img.shields.io/badge/Linux-FCC624?logo=linux&logoColor=black" /></a>
    <a href="https://github.com/Wildric-Auric/ucd/edit/main/README.md#windows" alt="Windows">
        <img src="https://custom-icon-badges.demolab.com/badge/Windows-0078D6?logo=windows11&logoColor=white"/></a>
</p>


------

u(ber)cd is a utility that allows you to stack and unstack directories meanwhile navigating using your favorite shells and terminals. <br>
The difference with what already exists is that this works out 
of the box on ANY terminal, and that it supports multiple platforms. The 
behaviour is very simple yet so poweful. <br>
This utility has no dependency.

## Build and install

You can either download the prebuilt binaries, or build from the source, the following describes the process of building and installing.

### Windows

* Clone the repository.
* Execute `build.bat`
* Make sure to have both `ucd.bat` and `_internal_ucd` in a directories that's in the **%PATH%** environment variable.

### Linux

The 2 first steps are basically the same, but execute `build.sh` instead of 
`build.bat`.
Since Linux shell scripts require creation of another process, we cannot execute
`ucd.sh` to actually change the working directory.
To overcome this, we add `ucd` logic to `~/.bashrc`. To do so execute `install.sh`.
Finally ensure to have the folder containing `_internal_ucd` in %$PATH% envrionment variable.

## Examples



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/othneildrew/Best-README-Template.svg?style=for-the-badge
[contributors-url]: https://github.com/othneildrew/Best-README-Template/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/othneildrew/Best-README-Template.svg?style=for-the-badge
[forks-url]: https://github.com/othneildrew/Best-README-Template/network/members
[stars-shield]: https://img.shields.io/github/stars/othneildrew/Best-README-Template.svg?style=for-the-badge
[stars-url]: https://github.com/othneildrew/Best-README-Template/stargazers
[issues-shield]: https://img.shields.io/github/issues/othneildrew/Best-README-Template.svg?style=for-the-badge
[issues-url]: https://github.com/othneildrew/Best-README-Template/issues
[license-shield]: https://img.shields.io/github/license/othneildrew/Best-README-Template.svg?style=for-the-badge
[license-url]: https://github.com/othneildrew/Best-README-Template/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/othneildrew
[product-screenshot]: images/screenshot.png
[Next.js]: https://img.shields.io/badge/next.js-000000?style=for-the-badge&logo=nextdotjs&logoColor=white
[Next-url]: https://nextjs.org/
[React.js]: https://img.shields.io/badge/React-20232A?style=for-the-badge&logo=react&logoColor=61DAFB
[React-url]: https://reactjs.org/
[Vue.js]: https://img.shields.io/badge/Vue.js-35495E?style=for-the-badge&logo=vuedotjs&logoColor=4FC08D
[Vue-url]: https://vuejs.org/
[Angular.io]: https://img.shields.io/badge/Angular-DD0031?style=for-the-badge&logo=angular&logoColor=white
[Angular-url]: https://angular.io/
[Svelte.dev]: https://img.shields.io/badge/Svelte-4A4A55?style=for-the-badge&logo=svelte&logoColor=FF3E00
[Svelte-url]: https://svelte.dev/
[Laravel.com]: https://img.shields.io/badge/Laravel-FF2D20?style=for-the-badge&logo=laravel&logoColor=white
[Laravel-url]: https://laravel.com
[Bootstrap.com]: https://img.shields.io/badge/Bootstrap-563D7C?style=for-the-badge&logo=bootstrap&logoColor=white
[Bootstrap-url]: https://getbootstrap.com
[JQuery.com]: https://img.shields.io/badge/jQuery-0769AD?style=for-the-badge&logo=jquery&logoColor=white
[JQuery-url]: https://jquery.com 


