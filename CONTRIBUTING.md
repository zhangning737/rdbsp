# Contributing

We welcome new contributors to this project to help make the rdbsp code better and more effective for our scientific and educational users. Contributions can take on a variety of forms, such as bug reports, feature requests, code documentation updates, user tutorials, feature implementations, bugfixes, and more.

When contributing to his repository, please first discuss the change you wish to make via issue, email, or any other method with owners of this repository before making a change.

We recommand discuss some change for better framework, memory management, and more efficient solver. Parallelization is also in consideration.

## Our Standards

- Currently code follows the [C++98 standard](http://www.cplusplus.com/doc/oldtutorial/), but [C++11 standard] is recommanded for further development. 
- Using welcoming and inclusive language.
- Being respectful of differing viewpoints and experiences.
- Gracefully accepting constructive criticism.
- Focusing on what is best for the community.
- Showing empathy towards other community members.


## Pull Request Process

One of the easiest ways to contribute is by using the software and submitting bug reports and feature requests as issues in the [Issues section](https://github.com/zhangning737/rdbsp/issues). 
Before filing a new issue please check that your issue has not already been submitted. 
If it has, 'like' the issue and add any additional feedback you have to the issue thread in a comment.
If your issue has not already been filed, create a new issue and provide a detailed description of the problem or new idea/suggestion. 
The code owners will review new issues, provide feedback, and decide if and when to implement the changes needed to resolve the issue.

## Working on an Issue

1. Before you set out to tackle an issue, discuss your implementation plans with the code owners on the issue page.
    
    Especially for code additions needed to add new features, it is important to discuss your implementation ideas with the code owners to ensure that the software design is relatively well thought out and fits with the rest of the codebase.
    
2. Create fork of the rdbsp repo on your account.

    Click the "Fork" button near the top of any rdbsp Github webpage.

3. Connect your fork to the upstream repo

    ```
    git remote add upstream https://github.com/zhangning737/rdbsp.git
    ```

4. Clone your forked rdbsp repo to your local machine.

    ```
    git clone --recurse-submodules https://github.com/YOUR_USERNAME/rdbsp
    ```

5. Create a new feature branch from the development branch.

    ```
    git checkout master
    git branch your-branch-name
    git checkout your-branch-name
    ```

6. Implement your changes keeping the scope of changes limited to the specified issue.

7. Document your changes by adding to the [Changelog](./CHANGELOG.md).

8. Update your new branch with any upstream changes and resolve any conflicts.

    ```
    git fetch upstream
    git checkout master
    git merge upstream/master
    git checkout your-branch-name
    git rebase master
    ```

9. Make sure your changes do not break any of the existing functionality by running the tests locally.

    
10. Push your local changes to your forked rdbsp repo.

    ```
    git push origin your-branch-name
    ```

11. Submit a pull request




