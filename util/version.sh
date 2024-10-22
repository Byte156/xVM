#!/bin/bash

# Read the version from version.txt
if [[ -f "version.txt" ]]; then
  version=$(cat version.txt)
else
  echo "# version.txt not found"
  exit 1
fi

# Split the version into major, minor, and build components
IFS='.' read -r major minor build <<< "$version"

# Increment the appropriate version component
if [[ $1 == "build" ]]; then
  build=$((build + 1))
elif [[ $1 == "minor" ]]; then
  minor=$((minor + 1))
elif [[ $1 == "major" ]]; then
  major=$((major + 1))
else
  echo "# Invalid argument. Use 'build', 'minor', or 'major'."
  exit 1
fi

# Construct the new version
new_version="${major}.${minor}.${build}"

# Write the new version back to version.txt
echo "$new_version" > version.txt

echo "# New version: $new_version"
